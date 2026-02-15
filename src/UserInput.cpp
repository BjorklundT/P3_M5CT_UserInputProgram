#include "UserInput.h"
#include <iostream>
#include <string>
#include <stdexcept>

//========================================
// PRIVATE namespace: Helper Methods
//========================================
namespace {

	//==VALIDATE-INPUT-PRMT==: No empty inputs
	std::string promptNonEmptyLine(const std::string& prompt) {
		std::string input;
		while (true) {
			std::cout << prompt;
			if (!std::getline(std::cin, input)) {
				throw std::runtime_error("Input stream failure while reading user input.");
			}
			if (!input.empty()) {
				return input;
			}
			std::cout << "Input cannot be empty. Please try again.\n";
		}
	}

	//==VALIDATE-INPUT-PRMT==: Due date validation
	std::string promptValidDueDate(const std::string& prompt) {
		while (true) {
			std::string input = promptNonEmptyLine(prompt);
			if (input.size() != 10 || input[2] != '/' || input[5] != '/') {
				std::cout << "Invalid format. Use MM/DD/YYYY.\n";
				continue;
			}
			const std::string monthStr = input.substr(0, 2);
			const std::string dayStr   = input.substr(3, 2);
			const std::string yearStr  = input.substr(6, 4);
			try {
				const int month = std::stoi(monthStr);
				const int day   = std::stoi(dayStr);
				const int year  = std::stoi(yearStr);
				if (month < 1 || month > 12) {
					std::cout << "Invalid month.\n";
					continue;
				}
				if (day < 1 || day > 31) {
					std::cout << "Invalid day.\n";
					continue;
				}
				if (year < 1000 || year > 9999) {
					std::cout << "Invalid year.\n";
					continue;
				}
				return input;
			} catch (const std::invalid_argument&) {
				std::cout << "Date must contain numbers only.\n";
			} catch (const std::out_of_range&) {
				std::cout << "Date values are out of range.\n";
			}
		}
	}

	//==FORMAT==: Format date for printout
	std::string formatDateToLongForm(const std::string& shortDate) {
		const std::string months[12] = {
			"January","February","March","April","May","June",
			"July","August","September","October","November","December"
		};

		const int month = std::stoi(shortDate.substr(0, 2));
		const std::string day  = shortDate.substr(3, 2);
		const std::string year = shortDate.substr(6, 4);

		return months[month - 1] + " " + day + ", " + year;
	}
}//END PRIVATE namespace==================

//========================================
// PUBLIC namespace
//========================================
namespace ct5 {

	//==PRMT==: Main Menu PROMPT
	int promptMenuChoice(int minOption, int maxOption) {
		while (true) {
			std::string input = promptNonEmptyLine("Enter your choice: ");
			try {
				int choice = std::stoi(input);
				if (choice >= minOption && choice <= maxOption) {
					return choice;
				}
			} catch (const std::invalid_argument&) {
			} catch (const std::out_of_range&) {
			}
			std::cout << "Invalid choice. Please enter a number from "
					  << minOption << " to " << maxOption << ".\n";
		}
	}

	//==INPUT==: Collect user input
	std::string getUserInfoBlock() {
		const std::string projectName = promptNonEmptyLine("Project Name: ");
		const std::string fullName    = promptNonEmptyLine("Full Name: ");
		const std::string schoolName  = promptNonEmptyLine("School Name: ");
		const std::string courseName  = promptNonEmptyLine("Course Name: ");
		const std::string profName    = promptNonEmptyLine("Professor Name: ");
		const std::string shortDate   = promptValidDueDate("Project Due Date (MM/DD/YYYY): ");
		const std::string dueDate     = formatDateToLongForm(shortDate);
		//==FORMAT==: formats input
		std::string block;
		block += "Project Name: " + projectName + "\n";
		block += "Student Name: " + fullName + "\n";
		block += "School Name: " + schoolName + "\n";
		block += "Course Name: " + courseName + "\n";
		block += "Professor Name: Professor " + profName + "\n";
		block += "Project Due Date: " + dueDate + "\n";
		return block;
	}

	//==PRMT-BOOL==: yes or no prompt
	bool promptYesNo(const std::string& prompt) {
		while (true) {
			std::string input = promptNonEmptyLine(prompt + " (Y/N): ");

			if (input == "Y" || input == "y") return true;
			if (input == "N" || input == "n") return false;

			std::cout << "Please enter Y or N.\n";
		}
	}
}//END PUBLIC namespace==================
