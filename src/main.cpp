#include <exception>
#include <iostream>
#include <string>
#include <thread>
#include "UserInput.h"
#include "FileOps.h"
#include "ConsoleUI.h"

//========================================
// PRIVATE namespace
//========================================
namespace {
    const std::string kInputFile  = "CSC450_CT5_mod5.txt";
    const std::string kOutputFile = "CSC450-mod5-reverse.txt";
}//END PRIVATE namespace==================

//========================================
// Main method
//========================================
int main() {
    try {
        // Text File Header captured at startup (first 4 lines to be safe)
    	// I did not want to lose the header content within all my manipulation
        const std::string baselineHeader = ct5::readFirstNLines(kInputFile, 4);

        while (true) {
            ct5::printMenu();
            const int choice = ct5::promptMenuChoice(1, 7);
            //===========================
            //Option 7: Exit
            //===========================
            if (choice == 7) {
                ct5::printStatus("Exiting program.");
                return 0;
            }

            switch (choice) {
            	//===========================
            	//Option 1: Full Program Run
            	//===========================
                case 1: {
                    if (ct5::promptYesNo("Reset program before continuing?")) {
                        ct5::resetFileToHeaderOnly(kInputFile, baselineHeader);
                        ct5::deleteFile(kOutputFile);
                        ct5::printStatus("Program reset complete (mod5 reset, reverse deleted if present).");
                    }

                    const std::string infoBlock = ct5::getUserInfoBlock();
                    ct5::rewriteFileWithHeaderAndData(kInputFile, baselineHeader, infoBlock);
                    ct5::printStatus("Updated mod5 file (kept header, replaced rest).");

                    if (ct5::promptYesNo("Create/update reverse file now?")) {
                        bool existed = false;
                        std::thread worker([&]() {
                            existed = ct5::reverseFileToFile(kInputFile, kOutputFile);
                        });
                        worker.join();
                        if (existed) {
                            ct5::printStatus("Reverse file existed, it was cleared and rewritten.");
                        } else {
                            ct5::printStatus("Reverse file did not exist, new file created.");
                        }
                    } else {
                        ct5::printStatus("Skipped creating the reverse file.");
                    }

                    ct5::pressEnterToContinue();
                    break;
                }
                //===========================
                //Option 2: Reset Program back to Original State
                //===========================
                case 2: {
                    ct5::printStatus("This will reset the mod5 file and delete the reverse file.");
                    if (ct5::promptYesNo("Continue?")) {
                        ct5::resetFileToHeaderOnly(kInputFile, baselineHeader);
                        const bool deleted = ct5::deleteFile(kOutputFile);

                        ct5::printStatus("mod5 file reset.");
                        ct5::printStatus(deleted ? "Reverse file deleted." : "Reverse file did not exist.");
                    }
                    ct5::pressEnterToContinue();
                    break;
                }
                //===========================
                //Option 3: Read mod5 Text File
                //===========================
                case 3: {
                    ct5::printFileContents("mod5 File", ct5::readFile(kInputFile));
                    ct5::pressEnterToContinue();
                    break;
                }
                //===========================
                //Option 4: Read Reverse File
                //===========================
                case 4: {
                    if (!ct5::fileExists(kOutputFile)) {
                        ct5::printStatus("Reverse file does not exist.");
                    } else {
                        ct5::printFileContents("Reverse File", ct5::readFile(kOutputFile));
                    }
                    ct5::pressEnterToContinue();
                    break;
                }
                //===========================
                //Option 5: Delete Reverse File
                //===========================
                case 5: {
                    if (!ct5::fileExists(kOutputFile)) {
                        ct5::printStatus("Reverse file does not exist.");
                    } else if (ct5::promptYesNo("Delete reverse file?")) {
                        ct5::deleteFile(kOutputFile);
                        ct5::printStatus("Reverse file deleted.");
                    }
                    ct5::pressEnterToContinue();
                    break;
                }
                //===========================
                //Option 6: Reset mod5 file
                //===========================
                case 6: {
                    if (ct5::promptYesNo("Reset mod5 file to original header only?")) {
                        ct5::resetFileToHeaderOnly(kInputFile, baselineHeader);
                        ct5::printFileContents("mod5 File Now", ct5::readFile(kInputFile));
                    }
                    ct5::pressEnterToContinue();
                    break;
                }
                //===========================
                //Default: 	Print Invalid option
                //			Press Enter to Continue logic
                //===========================
                default:
                    ct5::printStatus("Invalid option.");
                    ct5::pressEnterToContinue();
                    break;
            }
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << '\n';
        return 1;
    }
}
