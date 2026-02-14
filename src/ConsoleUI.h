#ifndef CT5_CONSOLEUI_H
#define CT5_CONSOLEUI_H

#include <string>

namespace ct5 {
    void printMenu();
    void printHeader(const std::string& title);
    void printStatus(const std::string& message);
    void printFileContents(const std::string& title, const std::string& contents);
    void pressEnterToContinue();
}

#endif
