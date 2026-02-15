#ifndef CT5_FILEOPS_H
#define CT5_FILEOPS_H

#include <string>


//========================================
// PUBLIC namespace
//========================================
namespace ct5 {

    /** ==READ==
     * @brief Reads an entire file into a single string.
     * @param path File path to read.
     * @return Full file contents.
     * @throws std::runtime_error if the file cannot be opened or read.
     */
    std::string readFile(const std::string& path);

    /** ==WRITE==
     * @brief Writes data to a file, creating it if needed, truncating if it exists.
     * @param path Output file path.
     * @param data Data to write.
     * @return true if the file existed before writing (and was cleared), false if newly created.
     * @throws std::runtime_error on open/write failure.
     */
    bool writeToFile(	const std::string& path,
    					const std::string& data);

    /** ==WRITE-REVERSE==
     * @brief Reads the input file, reverses all characters, writes the result to output file.
     * @param inputPath File to read.
     * @param outputPath File to create/overwrite with reversed output.
     * @return true if output existed before writing, false if newly created.
     */
    bool reverseFileToFile(	const std::string& inputPath,
    						const std::string& outputPath);

    /** ==STORE==
     * @brief Rewrites the target file by restoring the baseline header and then writing new data.
     *
     * This function truncates the file, writes baselineHeader (expected to include newlines),
     * then writes the new data block.
     *
     * @param path File to rewrite.
     * @param baselineHeader Header text to preserve at the top of the file.
     * @param data New data to write after the header.
     */
    void rewriteFileWithHeaderAndData(	const std::string& path,
    									const std::string& baselineHeader,
										const std::string& data);

    /** ==RETURN==
     * @brief Checks if a file exists at the provided path.
     * @param path File path to check.
     * @return true if file exists, otherwise false.
     */
    bool fileExists(const std::string& path);

    /** ==DELETE==
     * @brief Deletes a file if it exists.
     * @param path File path to delete.
     * @return true if file was deleted, false if it did not exist or could not be deleted.
     */
    bool deleteFile(const std::string& path);

    /** ==READ==
     * @brief Reads the first N lines of a file and returns them joined with '\n'.
     * @param path File path to read.
     * @param n Number of lines to read.
     * @return The first N lines joined, ending with '\n' if at least one line was read.
     */
    std::string readFirstNLines(const std::string& path, int n);

    /** ==RESET==
     * @brief Resets a file to header-only content by truncating then writing headerText.
     * @param path File path to reset.
     * @param headerText Header text to write.
     */
    void resetFileToHeaderOnly(	const std::string& path,
    							const std::string& headerText);
}

#endif
