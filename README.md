# School Management System

## Overview
This School Management System is a console-based C++ application designed to manage students and course enrollments efficiently.  
It features modular design with Object-Oriented Programming (OOP) principles and optimized data structures (DSA) for fast operations.

## Features
- **Student Management**: Add students with ID, name, and password with input validation.
- **Course Enrollment**: Enroll and remove courses for students (maximum 5 courses per student).
- **Student Information**: Display student details and enrolled courses.
- **Authentication**: Secure login system for each student.
- **Optimized Data Handling**: 
  - Fast student lookup using `std::unordered_map` (O(1)).
  - Courses stored in `std::vector` for dynamic management.
- **Input Validation**: Ensures valid IDs, names, and prevents invalid operations.

## Technologies & Concepts Used
- **Programming Language**: C++
- **OOP Principles**: Encapsulation, modularity
- **Data Structures & Algorithms**: 
  - `std::unordered_map` for fast student lookup
  - `std::vector` for course management
  - `std::find`, `std::all_of` for validation
- **Build System**: CMake
- **IDE Tested On**: CLion

## Installation
1. Clone the repository:  
`git clone https://github.com/IbrahimHashem0/School-Management-System.git`
2. Navigate to the project folder:  
`cd School-Management-System`
3. Create a build directory and compile:  
`mkdir build`  
`cd build`  
`cmake ..`  
`cmake --build .`
4. Run the application:  
`./School_Management_System`  *(On Windows: School_Management_System.exe)*

## Usage
Run the program and follow the console menu:
- Add Student
- Enroll in a Course
- Remove a Course
- Show Student Info
- Exit

Notes:
- Maximum 5 courses per student.
- Students must login using ID and password for course operations and info display.

## Future Improvements
- Add persistent storage (e.g., SQLite or files) to save student data.
- Implement search and sorting for students.
- Add role-based access for admins and students.
- Integrate a GUI for more interactive experience.

## License
This project is open-source under the MIT License.
