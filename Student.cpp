#include "Student.h"
#include <algorithm>

Student::Student(const string& id, const string& name, const string& password)
    : id(id), name(name), password(password) {}

string Student::getId() const { return id; }
string Student::getName() const { return name; }
string Student::getPassword() const { return password; }
vector<string>& Student::getEnrolledCourses() { return enrolledCourses; }

void Student::enrollCourse(const string& course) {
    if (enrolledCourses.size() < 5) {
        enrolledCourses.push_back(course);
        cout << "Enrolled in course: " << course << "\n";
    } else {
        cout << "Maximum course limit reached.\n";
    }
}

void Student::removeCourse(const string& course) {
    auto it = find(enrolledCourses.begin(), enrolledCourses.end(), course);
    if (it != enrolledCourses.end()) {
        enrolledCourses.erase(it);
        cout << "Course removed: " << course << "\n";
    } else {
        cout << "Course not found.\n";
    }
}

void Student::showStudentInfo() const {
    cout << "ID: " << id << "\n";
    cout << "Name: " << name << "\n";
    cout << "Enrolled Courses:\n";
    if (enrolledCourses.empty()) {
        cout << "No courses enrolled.\n";
    } else {
        for (const auto& c : enrolledCourses)
            cout << "- " << c << "\n";
    }
}
