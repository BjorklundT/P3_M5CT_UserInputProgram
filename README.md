# Module 5 – Secure User Input & File Manipulation (Critical Thinking)

## 📌 Project Overview

This project implements a secure, menu-driven C++ application that:

- Collects validated user input  
- Stores structured metadata into a provided file (`CSC450_CT5_mod5.txt`)  
- Preserves the original header content  
- Rewrites and manages file content safely  
- Reverses the entire file into a separate output file  
- Demonstrates basic multithreading using `std::thread`  
- Applies structured modular design using header and implementation files  

While the assignment requirements were straightforward, I intentionally expanded this project to incorporate abstraction, namespace organization, safe file handling practices, and controlled concurrency.

---

## 📂 Files Used

### Provided File
```
CSC450_CT5_mod5.txt
```

### Generated File
```
CSC450-mod5-reverse.txt
```

The reverse file is created automatically if it does not exist, or cleared and rewritten if it already exists.

---

## 🧠 Program Design Philosophy

Rather than placing all logic inside `main()`, I structured the program into modular components:

- **ConsoleUI** – Handles all user-facing output and formatting  
- **UserInput** – Collects and validates all user input  
- **FileOps** – Handles all file operations (read, write, reset, reverse, delete)  

This separation of concerns improves readability, maintainability, and testability.

I also used:

- A shared project namespace (`ct5`) to prevent naming conflicts  
- Anonymous namespaces inside `.cpp` files for internal helper functions  
- Doxygen-style documentation in header files to clearly describe public interfaces  

---

## 🗂 Project Structure

### `main.cpp`

Controls overall program flow:

- Loads baseline header (first 4 lines of the provided file)  
- Runs a menu-driven loop  
- Routes user selections to appropriate module functions  
- Demonstrates controlled multithreading for file reversal  
- Implements structured exception handling  

---

### `ConsoleUI.h / ConsoleUI.cpp`

Handles all console output:

- Menu printing  
- Status messages  
- File content display  
- “Press Enter to continue” logic  

This keeps formatting consistent and prevents clutter inside `main()`.

---

### `UserInput.h / UserInput.cpp`

Handles all input and validation:

- Prevents empty inputs  
- Validates due date format (`MM/DD/YYYY`)  
- Converts date into long-form format (`Month DD, YYYY`)  
- Collects all metadata into a formatted block for file storage  
- Handles numeric menu validation  
- Handles yes/no confirmations  

This module centralizes all input safety logic.

---

### `FileOps.h / FileOps.cpp`

Handles all file operations:

- `readFile()` – Reads full file into memory  
- `writeToFile()` – Writes data safely (truncates or creates)  
- `readFirstNLines()` – Extracts header lines  
- `rewriteFileWithHeaderAndData()` – Preserves header while replacing content  
- `resetFileToHeaderOnly()` – Restores file to baseline  
- `reverseFileToFile()` – Reverses entire file contents  
- `fileExists()` – Checks file existence  
- `deleteFile()` – Safely deletes file using `std::filesystem`  

All file errors throw `std::runtime_error`, which are caught in `main()`.

---

## 🔄 Menu Flow (CRUD Functionality)

The program runs as a structured menu with the following options:

1. Full Program Run  
2. Reset Program to Original State  
3. Read mod5 Text File  
4. Read Reverse File  
5. Delete Reverse File  
6. Reset mod5 File  
7. Exit  

This design allows:

- Repeated testing without restarting program  
- Controlled reset functionality  
- Clean file state management  
- Interactive exploration of file changes  

---

## 📄 Header Preservation Strategy

The assignment required preserving the top rows of the provided file.

To support this safely while also allowing reset functionality:

- The first 4 lines are captured at startup as a `baselineHeader`  
- Any rewrite operation restores this header first  
- All content below the header can be cleared or replaced safely  

This approach allows full file manipulation while guaranteeing header integrity.

---

## 🧵 Concurrency Implementation

Although threading was not required, this module focused on concurrency vulnerabilities, so I incorporated `std::thread` intentionally.

The reverse file creation runs inside a worker thread:

- A worker thread performs `reverseFileToFile()`  
- `join()` is called immediately afterward to prevent race conditions  
- This ensures safe synchronization before status reporting  

The threading is controlled and deterministic to avoid introducing unsafe concurrency patterns.

---

## 🔐 Secure Coding Concepts Applied

- Input validation and range checking  
- Exception-based error handling  
- Controlled file truncation  
- File existence verification before deletion  
- Safe namespace usage  
- Separation of public interface and implementation  
- Controlled thread lifecycle management  

---

## 🎯 Concepts Practiced

- File I/O (read, write, truncate, binary mode)  
- Header preservation and controlled file rewriting  
- String parsing and formatting  
- Menu-driven program structure  
- Modular abstraction using `.h` and `.cpp`  
- Namespace organization  
- Anonymous namespace for private helpers  
- Basic multithreading with `std::thread`  
- Exception handling using `try/catch`  

---

## 📝 Personal Notes

This project evolved beyond the minimum assignment requirements. While the core task was simple (collect input and reverse a file), I used it as an opportunity to:

- Practice modular design  
- Experiment with namespaces  
- Work with header files more intentionally  
- Implement structured validation  
- Build a cleaner user interface  
- Explore threading safely  

My goal was not only to complete the assignment, but to reinforce secure coding practices and build something structured, readable, and extensible.
