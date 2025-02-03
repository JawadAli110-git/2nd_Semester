#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Subject {
    string subjectName;
};

struct Student {
    int id;
    static const int numSubjects = 3;
    Subject subjects[numSubjects];
};

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    // Declare and initialize vector with numStudents size
    vector<Student> students(numStudents);

    // Input data
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter ID for student " << i + 1 << ": ";
        cin >> students[i].id;
        cin.ignore();

        for (int j = 0; j < Student::numSubjects; j++) {
            cout << "Enter subject " << j + 1 << " for student " << students[i].id << ": ";
            getline(cin, students[i].subjects[j].subjectName);
        }
    }

    // Display data
    cout << "\nStudent Data:\n";
    for (const auto& student : students) {
        cout << "Student ID: " << student.id << "\nSubjects: ";
        for (const auto& subject : student.subjects) {
            cout << subject.subjectName << ", ";
        }
        cout << "\n";
    }

    return 0;
}
