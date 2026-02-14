#ifndef CT5_FILEOPS_H
#define CT5_FILEOPS_H

#include <string>

namespace ct5 {

    // Read file as a string
    std::string readFile(const std::string& path);

    // Writes data to path; returns true if file existed, false if newly created.
    bool writeToFile(const std::string& path, const std::string& data);

    // Reverse input file to output file; returns true if output existed.
    bool reverseFileToFile(const std::string& inputPath, const std::string& outputPath);

    // Keeps first 4 lines, clears rest, then writes data starting line 5.
    void rewriteFileWithHeaderAndData(const std::string& path, const std::string& data);

    // Returns true if file exists
    bool fileExists(const std::string& path);

    // Deletes file if it exists; returns true if deleted, false if not found
    bool deleteFile(const std::string& path);

    // Reads first N lines (joined with '\n', ends with '\n' if any lines exist)
    std::string readFirstNLines(const std::string& path, int n);

    // Resets file to headerText only (truncates file first)
    void resetFileToHeaderOnly(const std::string& path, const std::string& headerText);
}

#endif
