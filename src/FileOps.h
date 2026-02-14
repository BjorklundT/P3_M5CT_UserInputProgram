#ifndef CT5_FILEOPS_H
#define CT5_FILEOPS_H

#include <string>

namespace ct5 {

    void appendToFile(const std::string& path,
                      const std::string& data);

    std::string readEntireFile(const std::string& path);

    void writeToFile(const std::string& path,
                     const std::string& data);

    void reverseFileToFile(const std::string& inputPath,
                           const std::string& outputPath);
}

#endif
