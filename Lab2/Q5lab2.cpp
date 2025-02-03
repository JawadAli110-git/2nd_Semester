#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the structure
struct Person {
    int id;
    string name;
};

// Comparator to sort by ID
bool compareById(const Person &a, const Person &b) {
    return a.id < b.id;
}

// Comparator to sort by the first character of the name
bool compareByNameFirstChar(const Person &a, const Person &b) {
    return a.name[0] < b.name[0];
}

// Function to print the vector of structures
void printPersons(const vector<Person> &persons) {
    for (const auto &person : persons) {
        cout << "ID: " << person.id << ", Name: " << person.name << endl;
    }
}

int main() {
    int N;
    cout << "Enter the number of structures (N): ";
    cin >> N;

    vector<Person> persons(N);
    //Person* persons = new Person[N];
    // Input data
    for (int i = 0; i < N; ++i) {
        cout << "Enter ID for person " << i + 1 << ": ";
        cin >> persons[i].id;
        cout << "Enter Name for person " << i + 1 << ": ";
        cin >> persons[i].name;
    }

    // Sort by ID
    sort(persons.begin(), persons.end(), compareById);
    cout << "\nSorted by ID:\n";
    printPersons(persons);

    // Sort by the first character of the name
    sort(persons.begin(), persons.end(), compareByNameFirstChar);
    cout << "\nSorted by the first character of the name:\n";
    printPersons(persons);

    return 0;
}