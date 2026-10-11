# Library Management System

A console-based Library Management System developed in **C++** using Object-Oriented Programming (OOP) principles. The project manages different types of library materials and supports searching, sorting, borrowing, returning, and file-based data persistence.

## Features

- **Manage Library Items:** Add and display books, magazines, DVDs, and research papers.
- **Search:** Find items by ID, title, creator, or publication year.
- **Sorting:** Sort items by publication year, type, availability, or title.
- **Borrowing and Returning:** Track borrowers, borrowing dates, and item availability.
- **Late Fee Calculation:** Calculate overdue fees according to the item type.
- **File Handling:** Save and load library data using text files.
- **Report Generation:** Generate reports containing item statistics, availability information, and the oldest and newest items.
- **Input Validation:** Handle invalid inputs and prevent duplicate item IDs.

## Object-Oriented Programming

This project demonstrates several core C++ concepts:

- **Encapsulation** — private data members with public getters and setters.
- **Inheritance** — `Book`, `Magazine`, `DVD`, and `ResearchPaper` inherit from `LibraryItem`.
- **Polymorphism** — virtual functions provide type-specific behavior.
- **Abstraction** — `LibraryItem` is an abstract base class.
- **Operator Overloading** — custom operators for comparison, year modification, and stream input/output.
- **Smart Pointers** — `std::unique_ptr` for automatic memory management.
- **STL Containers and Algorithms** — `std::map`, `std::vector`, and `std::sort`.
- **Exception Handling** — handling file and report generation errors.

## Project Structure

```text
LibraryManagement/
├── main.cpp
├── LibraryItem.h
├── LibraryItem.cpp
├── LibraryFunctions.h
├── LibraryFunctions.cpp
├── Book.h
├── Book.cpp
├── Magazine.h
├── Magazine.cpp
├── DVD.h
├── DVD.cpp
├── ResearchPaper.h
├── ResearchPaper.cpp
├── data.txt
└── README.md
```

## Requirements

- A C++ compiler supporting C++14 or later.
- A terminal or IDE, such as Visual Studio Code.

## How to Compile and Run

### 1. Clone the repository

```bash
git clone YOUR_REPOSITORY_URL
cd LibraryManagement
```

Replace `YOUR_REPOSITORY_URL` with your GitHub repository URL.

### 2. Compile the project

Using GCC or MinGW:

```bash
g++ -std=c++14 main.cpp LibraryFunctions.cpp LibraryItem.cpp Book.cpp DVD.cpp Magazine.cpp ResearchPaper.cpp -o library.exe
```

### 3. Run the program

On Windows:

```powershell
.\library.exe
```

On Linux or macOS, compile with `-o library` instead, then run:

```bash
./library
```

## Data Storage

The system uses a pipe-delimited text format to store library items. Each record contains the item type and its associated data. The program supports saving and loading the collection through `data.txt`.

A generated report is saved to `out.txt`.

## Learning Objectives

This project provided practical experience with class hierarchies, runtime polymorphism, smart pointers, STL containers, operator overloading, exception handling, and file input/output in C++.

## Author

**Dachi Kirkitadze**
