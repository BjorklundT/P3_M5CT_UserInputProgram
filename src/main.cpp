//============================================================================
// Name        : P3_M5CT_UserInputProgram.cpp
// Author      : Timothy Bjorklund
//============================================================================

#include <exception>
#include <iostream>
#include <string>

#include "UserInput.h"

namespace {
	const std::string kInputFile = "CSC450_CT5_mod5.txt";
	const std::string kOutputFile = "CSC450_CT5-reverse.txt";

    // TODO: Step 2: collectUserInput()
    // TODO: Step 3: appendToFile()
    // TODO: Step 4: reverseFileToFile()
}

int main() {
    try {
        std::cout << "Module 5 CT, User Input Program\n\n";

        std::string infoBlock = ct5::collectUserInfoBlock();
        std::cout << "\n--- Collected Info ---\n";
        std::cout << infoBlock;

        return 0;
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << '\n';
        return 1;
    }
}
