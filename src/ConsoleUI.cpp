#include "ConsoleUI.h"
#include <iostream>


//========================================
// PUBLIC namespace: Printouts Methods for Console
//========================================
namespace ct5 {

	//==MENU==: main menu
    void printMenu() {
        std::cout
			<< "\n================================\n"
			<< "Please select option to continue:"
			<< "\n================================\n\n"
			<< "1. Full Program Run\n"
			<< "2. Reset Program back to Original State\n"
			<< "3. Read mod5 Text File\n"
			<< "4. Read Reverse File\n"
			<< "5. Delete Reverse File\n"
			<< "6. Reset mod5 file\n"
			<< "7. Exit\n\n";
    }

    //==PRINT==: Title Header
    void printHeader(const std::string& title) {
        std::cout << "\n--- " << title << " ---\n";
    }

    //==PRINT==: Print any message
    void printStatus(const std::string& message) {
        std::cout << message << "\n";
    }

    //==PRINT==: Print out file contents
    void printFileContents(const std::string& title, const std::string& contents) {
        printHeader(title);
        std::cout << contents << "\n";
    }

    //==ENTER==: press enter to continue method
    void pressEnterToContinue() {
        std::cout << "\nPress Enter to return to the main menu...";
        std::string dummy;
        std::getline(std::cin, dummy);
    }
}//END PUBLIC namespace==================
