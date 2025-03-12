#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;
    int rollNumber;

public:
    void getStudentInfo() {
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cin.ignore();
    }

    void displayStudentInfo() {
        cout << "\nStudent Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll Number (only number): " << rollNumber << endl;
    }
};

class Marks : public Student {
protected:
    int numCourses;
    int *marks;

public:
    Marks() : marks(nullptr), numCourses(0) {}

    ~Marks() {
        delete[] marks;
    }

    void getMarks() {
        cout << "Enter the number of courses: ";
        cin >> numCourses;
        marks = new int[numCourses];

        for (int i = 0; i < numCourses; ++i) {
            cout << "Enter marks for course " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    void displayMarks() {
        cout << "\nMarks Obtained:" << endl;
        for (int i = 0; i < numCourses; ++i) {
            cout << "Course " << i + 1 << ": " << marks[i] << " marks" << endl;
        }
    }
};

class Result : public Marks {
public:
    void calculateResult() {
        int totalMarks = 0;
        for (int i = 0; i < numCourses; ++i) {
            totalMarks += marks[i];
        }

        double averageMarks = (numCourses > 0) ? static_cast<double>(totalMarks) / numCourses : 0;

        cout << "\nResult Summary:" << endl;
        cout << "Total Marks: " << totalMarks << endl;
        cout << "Average Marks: " << averageMarks << endl;
    }
};

int main() {
    Result studentResult;

    studentResult.getStudentInfo();
    studentResult.getMarks();

    studentResult.displayStudentInfo();
    studentResult.displayMarks();
    studentResult.calculateResult();

    return 0;
}