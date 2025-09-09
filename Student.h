#pragma once
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Student {
private:
    string id;
    string name;
    string password;
    vector<string> enrolledCourses;

public:
    Student(const string& id, const string& name, const string& password);

    string getId() const;
    string getName() const;
    string getPassword() const;

    vector<string>& getEnrolledCourses();

    void enrollCourse(const string& course);
    void removeCourse(const string& course);
    void showStudentInfo() const;
};
