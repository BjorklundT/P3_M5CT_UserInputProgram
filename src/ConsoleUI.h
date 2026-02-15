#ifndef CT5_CONSOLEUI_H
#define CT5_CONSOLEUI_H

#include <string>


//========================================
// PUBLIC namespace: PRINT methods
//========================================
namespace ct5 {

	/** ==PRINT-MENU==
	 * @brief Prints the main menu options to the console.
	 */
    void printMenu();

    /** ==PRINT-Header==
	 * @brief Prints a formatted header line to visually separate sections.
	 * @param title Title to display in the header.
	 */
    void printHeader(const std::string& title);

    /** ==PRINT-MSG==
     * @brief Prints a status message to the console.
     * @param message Message to display.
     */
    void printStatus(const std::string& message);

    /** ==PRINT-FILE==
     * @brief Prints file contents with a labeled header.
     * @param title Label used as the section header.
     * @param contents Full contents to display.
     */
    void printFileContents(	const std::string& title,
    						const std::string& contents);

    /** ==ENTER==
     * @brief Prompts the user to press Enter to continue.
     *
     * Uses getline so it works correctly with previous getline calls.
     */
    void pressEnterToContinue();
}

#endif
