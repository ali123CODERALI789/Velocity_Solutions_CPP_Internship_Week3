# Student Record Management System – Week 3 (C++ OOP & File Handling)

## Intern:
M. Ali Sajjad

## Internship Program
Velocity Solutions

##  Overview

This project was developed during Week 3 of the internship program. The main focus was on applying Object-Oriented Programming (OOP) principles and implementing file handling using C++. The system is designed to manage student academic records and basic contact information efficiently through a command-line interface.

The key operations include:
- Collecting and displaying student information (name, ID, marks, grades)
- Writing/reading student data to/from files
- Using OOP concepts like inheritance, encapsulation, and abstraction
- Searching student data by ID
- Managing a basic contact book for student IDs

---

## Objectives Covered

| Requirement                                           | Implemented | Description |
|-------------------------------------------------------|-------------|-------------|
| **Class with constructor, destructor**                |     Yes     | `Student`, `Graduate`, and `Contact` classes |
| **Inheritance**                                       |     Yes     | `Graduate` and `Contact` inherit from `Student` |
| **Encapsulation & Abstraction**                       |     Yes     | Attributes are private/protected with getter/setter functions |
| **File Handling** (`ifstream`, `ofstream`)            |     Yes     | Student info and contact data are saved/loaded using text files |
| **Polymorphism (display method)**                     |     Yes     | The `display()` function is overridden in child classes |
| **Search by Student ID**                              |     Yes     | ID lookup implemented via `searchID()` method in `Contact` class |
| **Contact Book (optional task)**                      |     Yes     | `Contact.txt` stores basic name + ID for quick lookup |

---

##  Features & How It Works

### 1. Add New Students
- User can input details for multiple students: name, student ID, and marks.
- Validation ensures name length ≤ 20, ID is ≤ 9 digits, and marks are between 0–100.

### 2. Grade Calculation
- A character grade (`A` to `F`) is assigned based on marks.
- Grades are calculated using a standard grading scale inside `Student::calculate_grade()`.

### 3. Graduation Eligibility
- The `Graduate` class checks whether a student is eligible to graduate (any grade except `F`).
- A status is saved per student (Eligible / Not eligible).

### 4. Contact Information
- The `Contact` class displays only student names and IDs.
- All contact data is saved in `Contact.txt`.

### 5. File Handling
- **Write Mode**: Overwrites the existing file with new student/contact data.
- **Append Mode**: Adds new student data to the existing file without deleting old entries.
- **Read Mode**: Reads and prints the content of `student.txt` or `Contact.txt`.

### 6. Search Student by ID
- Prompts user to enter a student ID and checks if it exists in the list.
- Displays a success/failure message based on result.

---

##  Sample Menu

Welcome to Student Record Management System.

Do you want to:

Write to an empty file and search student by ID

Read contents from the file database

Append new info to end of file database

Show all contacts

Exit


---

##  Key OOP Concepts Used

###  Encapsulation
- All class data members are kept private or protected.
- Access and modification are done via public methods.

###  Inheritance
- `Graduate` and `Contact` classes inherit from the base `Student` class.

###  Abstraction
- The system hides implementation details like file handling and internal data structures.

###  Polymorphism
- The `display()` method is declared `virtual` in the `Student` class and overridden in `Graduate` and `Contact`.

---

##  Files

- `OOP.cpp` – Main source file with all class definitions and logic
- `student.txt` – Stores student records: name, ID, marks, grade, and eligibility
- `Contact.txt` – Stores basic student contact info: name and ID

---

##  Conclusion

This system serves as a solid example of how real-world record management can be simulated using core C++ features. It helped reinforce understanding of:
- Dynamic memory allocation
- OOP design
- File I/O
- Data abstraction and validation

The code was built keeping readability, modularity, and reusability in mind.

---

