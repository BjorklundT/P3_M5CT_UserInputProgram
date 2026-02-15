#ifndef CT5_USERINPUT_H
#define CT5_USERINPUT_H

#include <string>


//========================================
// PUBLIC namespace
//========================================
namespace ct5 {

	/** ==GET-RETURN==
	 * @brief Collects assignment metadata from the user and returns a formatted text block.
	 *
	 * Prompts for project name, student name, school name, course name, professor name,
	 * and a due date (validated as MM/DD/YYYY then formatted to "Month DD, YYYY").
	 *
	 * @return A formatted block of text ready to be written to a file.
	 */
    std::string getUserInfoBlock();

    /** ==MENU-PRMT==
     * @brief Prompts the user to select a menu choice in a valid numeric range.
     * @param minOption Lowest valid menu option (inclusive).
     * @param maxOption Highest valid menu option (inclusive).
     * @return A validated integer menu choice.
     */
    int promptMenuChoice(int minOption, int maxOption);

    /** ==PRMT-BOOL==
     * @brief Prompts the user for a Yes/No decision.
     * @param prompt The question to display (Y/N will be appended).
     * @return true if user enters Y/y, false if user enters N/n.
     */
    bool promptYesNo(const std::string& prompt);
}

#endif
