#ifndef CT5_USERINPUT_H
#define CT5_USERINPUT_H

#include <string>

namespace ct5 {

    // Get all metadata and returns it as a formatted block of text.
    std::string GetUserInfoBlock();

    // Menu input helpers
    int promptMenuChoice(int minOption, int maxOption);
    bool promptYesNo(const std::string& prompt);

}

#endif
