#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int id;
    double salary;

public:
    virtual void getData() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter salary: ";
        cin >> salary;
        cin.ignore(); // Clear newline after reading salary
    }

    virtual void displayData() {
        cout << "Name: " << name << ", ID: " << id << ", Salary: " << salary;
    }

    virtual void bonus() {
        cout << ", Bonus: " << salary * 0.1 << endl;  // Default bonus 10%
    }

    virtual ~Person() {}
};

// Admin class derived from Person
class Admin : virtual public Person {
public:
    void getData() override {
        cout << "\n[Admin Info]\n";
        Person::getData();
    }

    void displayData() override {
        cout << "\n[Admin Data]\n";
        Person::displayData();
    }

    void bonus() override {
        cout << ", Admin Bonus: " << salary * 0.15 << endl;  // 15% bonus
    }
};

// Account class derived from Person
class Account : virtual public Person {
public:
    void getData() override {
        cout << "\n[Account Info]\n";
        Person::getData();
    }

    void displayData() override {
        cout << "\n[Account Data]\n";
        Person::displayData();
    }

    void bonus() override {
        cout << ", Account Bonus: " << salary * 0.12 << endl;  // 12% bonus
    }
};

// Master class inherits from both Admin and Account
class Master : public Admin, public Account {
public:
    void getData() override {
        cout << "\n[Master Info - Combined Role]\n";
        Person::getData();
    }

    void displayData() override {
        cout << "\n[Master Data]\n";
        Person::displayData();
    }

    void bonus() override {
        cout << ", Master Bonus: " << salary * 0.2 << endl;  // 20% bonus
    }
};
int main() {
    Person* p;

    Admin a;
    Account acc;
    Master m;

    // Admin
    p = &a;
    p->getData();
    p->displayData();
    p->bonus();

    // Account
    p = &acc;
    p->getData();
    p->displayData();
    p->bonus();

    // Master
    p = &m;
    p->getData();
    p->displayData();
    p->bonus();

    return 0;
}
