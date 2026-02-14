#include "UserInput.h"
#include <iostream>
#include <string>
#include <stdexcept>

//Private Name Space
namespace {
//========================================
// HELPER METHODS
// --Error Handling
//========================================
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

    std::string promptValidDueDate(const std::string& prompt) {
        while (true) {
            std::string input = promptNonEmptyLine(prompt);

            if (input.size() != 10 || input[2] != '/' || input[5] != '/') {
                std::cout << "Invalid format. Use MM/DD/YYYY.\n";
                continue;
            }

            std::string monthStr = input.substr(0, 2);
            std::string dayStr   = input.substr(3, 2);
            std::string yearStr  = input.substr(6, 4);

            try {
                int month = std::stoi(monthStr);
                int day   = std::stoi(dayStr);
                int year  = std::stoi(yearStr);

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

                return input;  // valid

            } catch (const std::invalid_argument&) {
                std::cout << "Date must contain numbers only.\n";
            } catch (const std::out_of_range&) {
                std::cout << "Date values are out of range.\n";
            }
        }
    }

    std::string formatDateToLongForm(const std::string& shortDate) {

        const std::string months[12] = {
            "January","February","March","April","May","June",
            "July","August","September","October","November","December"
        };

        int month = std::stoi(shortDate.substr(0, 2));
        std::string day  = shortDate.substr(3, 2);
        std::string year = shortDate.substr(6, 4);

        return months[month - 1] + " " + day + ", " + year;
    }
}

//Public Name Space
namespace ct5 {
//========================================
// Collect User Info
//========================================
    std::string collectUserInfoBlock() {

        std::string projectName = promptNonEmptyLine("Project Name: ");
        std::string fullName    = promptNonEmptyLine("Full Name: ");
        std::string schoolName    = promptNonEmptyLine("School Name: ");
        std::string courseName    = promptNonEmptyLine("Course Name: ");
        std::string profName    = promptNonEmptyLine("Professors Name: ");
        std::string shortDate = promptValidDueDate("Project Due Date (MM/DD/YYYY): ");
        std::string dueDate   = formatDateToLongForm(shortDate);

        std::string block;

        block += "Project Name: " + projectName + "\n";
        block += "Student Name: " + fullName + "\n";
        block += "School Name: " + schoolName + "\n";
        block += "Course Name: " + courseName + "\n";
        block += "Professor Name: Professor " + profName + "\n";
        block += "Project Due Date: " + dueDate + "\n";

        return block;
    }
}

