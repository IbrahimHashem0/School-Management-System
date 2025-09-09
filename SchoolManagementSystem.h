#pragma once
#include "Student.h"
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class SchoolManagementSystem {
private:
    unordered_map<string, Student*> studentsMap;
    vector<string> courses = {"OOP", "DB", "Network", "Web development", "Montag"};

public:
    void run();
private:
    void addStudent();
    void enrollInCourse();
    void removeCourse();
    void showStudentInfo();
    Student* authenticateStudent();
};
