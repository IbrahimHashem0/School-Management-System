#include "SchoolManagementSystem.h"

void SchoolManagementSystem::run() {
    while (true) {
        cout << "\n1- Add Student\n2- Enroll Course\n3- Remove Course\n4- Show Student Info\n5- Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addStudent(); break;
            case 2: enrollInCourse(); break;
            case 3: removeCourse(); break;
            case 4: showStudentInfo(); break;
            case 5: cout << "Exiting...\n"; return;
            default: cout << "Invalid option. Try again.\n";
        }
    }
}

void SchoolManagementSystem::addStudent() {
    string id, name, password;
    cout << "Enter student ID (numbers only): ";
    cin >> id; cin.ignore();
    if (!all_of(id.begin(), id.end(), ::isdigit)) { cout << "Invalid ID.\n"; return; }
    if (studentsMap.find(id) != studentsMap.end()) { cout << "ID already exists.\n"; return; }

    cout << "Enter student name: ";
    getline(cin, name);
    if (!all_of(name.begin(), name.end(), [](char c){ return isalpha(c) || c==' '; })) {
        cout << "Invalid name.\n"; return;
    }

    cout << "Enter password: ";
    getline(cin, password);
    if (password.empty()) { cout << "Password cannot be empty.\n"; return; }

    Student* s = new Student(id, name, password);
    studentsMap[id] = s;
    cout << "Student added successfully.\n";
}

Student* SchoolManagementSystem::authenticateStudent() {
    string id, password;
    cout << "Enter student ID: ";
    cin >> id; cin.ignore();
    cout << "Enter password: ";
    getline(cin, password);

    auto it = studentsMap.find(id);
    if (it == studentsMap.end() || it->second->getPassword() != password) {
        cout << "Invalid ID or password.\n";
        return nullptr;
    }
    return it->second;
}

void SchoolManagementSystem::enrollInCourse() {
    Student* student = authenticateStudent();
    if (!student) return;

    cout << "Available courses:\n";
    for (int i=0; i<courses.size(); i++) cout << i+1 << ". " << courses[i] << "\n";
    int choice; cin >> choice; cin.ignore();
    if (choice>=1 && choice<=courses.size()) student->enrollCourse(courses[choice-1]);
    else cout << "Invalid course number.\n";
}

void SchoolManagementSystem::removeCourse() {
    Student* student = authenticateStudent();
    if (!student) return;

    auto& enrolled = student->getEnrolledCourses();
    if (enrolled.empty()) { cout << "No courses enrolled.\n"; return; }

    cout << "Enrolled courses:\n";
    for (int i=0; i<enrolled.size(); i++) cout << i+1 << ". " << enrolled[i] << "\n";
    int choice; cin >> choice; cin.ignore();
    if (choice>=1 && choice<=enrolled.size()) student->removeCourse(enrolled[choice-1]);
    else cout << "Invalid course number.\n";
}

void SchoolManagementSystem::showStudentInfo() {
    Student* student = authenticateStudent();
    if (student) student->showStudentInfo();
}
