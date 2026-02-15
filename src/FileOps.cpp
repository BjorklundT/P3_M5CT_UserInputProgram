#include "FileOps.h"
#include <fstream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <iterator>
#include <filesystem>

//========================================
// PRIVATE namespace: Helper Methods
//========================================
namespace {

	//==FILE-ERROR==: File Error Types
	enum class FileErrorType {
		ReadOpen,
		WriteOpen,
		WriteFailure
	};

	//==FILE-ERROR==: File Connection Errors Method
	void fileConnectionError(FileErrorType type, const std::string& path) {
		switch (type) {
			case FileErrorType::ReadOpen:
				throw std::runtime_error("Failed to open file for reading: " + path);
			case FileErrorType::WriteOpen:
				throw std::runtime_error("Failed to open file for writing: " + path);
			case FileErrorType::WriteFailure:
				throw std::runtime_error("Failed while writing to file: " + path);
		}
		throw std::runtime_error("Unknown file error for: " + path);
	}

}//END PRIVATE namespace==================

//========================================
// PUBLIC namespace
//========================================
namespace ct5 {

	//==CHECK==: Does File Exist
	bool fileExists(const std::string& path) {
		std::ifstream test(path);
		return test.good();
	}

	//==DELETE==: file
	bool deleteFile(const std::string& path) {
	    std::error_code ec;
	    if (!std::filesystem::exists(path, ec)) return false;
	    return std::filesystem::remove(path, ec);
	}

	//==READ==: First number of Lines
	std::string readFirstNLines(const std::string& path, int n) {
		std::ifstream in(path);
		if (!in) {
			fileConnectionError(FileErrorType::ReadOpen, path);
		}
		std::string line;
		std::string result;
		int count = 0;
		while (count < n && std::getline(in, line)) {
			result += line + "\n";
			++count;
		}
		return result;
	}

	//==RESET==: mod5 text file back to original
	void resetFileToHeaderOnly(const std::string& path, const std::string& headerText) {
		std::ofstream out(path, std::ios::trunc);
		if (!out) {
			fileConnectionError(FileErrorType::WriteOpen, path);
		}
		out << headerText;
		if (!out) {
			fileConnectionError(FileErrorType::WriteFailure, path);
		}
	}

	//==REWRITE==: write header text back into mod5 text file
	void rewriteFileWithHeaderAndData(	const std::string& path,
										const std::string& baselineHeader,
										const std::string& data) {

		// Rewrite file (erase old content)
		std::ofstream out(path, std::ios::trunc);
		if (!out) {
			fileConnectionError(FileErrorType::WriteOpen, path);
		}
		out << baselineHeader;
		out << data;
		if (!out) {
			fileConnectionError(FileErrorType::WriteFailure, path);
		}
	}

	//==READ==: Simple read any file method
	std::string readFile(const std::string& path) {
		std::ifstream in(path, std::ios::in | std::ios::binary);
		if (!in) {
			fileConnectionError(FileErrorType::ReadOpen, path);
		}

		std::string content((std::istreambuf_iterator<char>(in)),
							 std::istreambuf_iterator<char>());

		if (!in.good() && !in.eof()) {
			fileConnectionError(FileErrorType::ReadOpen, path);
		}
		return content;
	}

	//==WRITE==: simple write to file method
	bool writeToFile(const std::string& path, const std::string& data) {
		const bool existed = fileExists(path);

		std::ofstream out(path, std::ios::out | std::ios::binary | std::ios::trunc);
		if (!out) {
			fileConnectionError(FileErrorType::WriteOpen, path);
		}
		out.write(data.c_str(), static_cast<std::streamsize>(data.size()));
		if (!out) {
			fileConnectionError(FileErrorType::WriteFailure, path);
		}
		return existed;
	}

	//==REVERSE==: reverse file method
	bool reverseFileToFile(	const std::string& inputPath,
							const std::string& outputPath) {
		std::string content = readFile(inputPath);
		std::reverse(content.begin(), content.end());
		return writeToFile(outputPath, content);
	}

}//END PUBLIC namespace==================
