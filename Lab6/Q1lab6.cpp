#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;

public:
    BankAccount(const string& accNum, double initialBalance)
        : accountNumber(accNum), balance(initialBalance) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << " into account " << accountNumber << "\n";
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " from account " << accountNumber << "\n";
        } else {
            cout << "Insufficient funds in account " << accountNumber << "\n";
        }
    }

    virtual void endOfMonthProcess() {}
    virtual void display() const {
        cout << "Account: " << accountNumber << ", Balance: " << balance << "\n";
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
    double interestRate;

public:
    SavingsAccount(const string& accNum, double initialBalance, double rate)
        : BankAccount(accNum, initialBalance), interestRate(rate) {}

    void endOfMonthProcess() override {
        balance += balance * interestRate;
        cout << "Interest added to account " << accountNumber << "\n";
    }
};

class CheckingAccount : public BankAccount {
    double overdraftLimit;

public:
    CheckingAccount(const string& accNum, double initialBalance, double limit)
        : BankAccount(accNum, initialBalance), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (balance - amount >= -overdraftLimit) {
            balance -= amount;
            cout << "Withdrawn: " << amount << " (Overdraft OK)\n";
        } else {
            cout << "Overdraft limit reached for account " << accountNumber << "\n";
        }
    }
};

class BusinessAccount : public BankAccount {
    double taxRate;

public:
    BusinessAccount(const string& accNum, double initialBalance, double tax)
        : BankAccount(accNum, initialBalance), taxRate(tax) {}

    void deposit(double amount) override {
        double tax = amount * taxRate;
        balance += (amount - tax);
        cout << "Deposited: " << amount - tax << " after tax in account " << accountNumber << "\n";
    }
};

class User {
protected:
    string name;

public:
    User(const string& userName) : name(userName) {}
    virtual void accessAccount(BankAccount &account) = 0;
    virtual ~User() {}
};

class Customer : public User {
public:
    Customer(const string& userName) : User(userName) {}

    void accessAccount(BankAccount &account) override {
        account.display();
    }

    void deposit(BankAccount &account, double amount) {
        account.deposit(amount);
    }

    void withdraw(BankAccount &account, double amount) {
        account.withdraw(amount);
    }
};

class Employee : public User {
public:
    Employee(const string& userName) : User(userName) {}
};

class Teller : public Employee {
public:
    Teller(const string& userName) : Employee(userName) {}

    void accessAccount(BankAccount &account) override {
        account.display();
    }
};

class Manager : public Employee {
public:
    Manager(const string& userName) : Employee(userName) {}

    void accessAccount(BankAccount &account) override {
        account.display();
    }

    void overrideLimit(CheckingAccount &account, double newLimit) {
        cout << "Manager set new overdraft limit: " << newLimit << "\n";
    }
};

int main() {
    SavingsAccount savings("SA001", 1000.0, 0.02);
    CheckingAccount checking("CA001", 500.0, 200.0);
    BusinessAccount business("BA001", 2000.0, 0.05);

    Customer customer("Ahmed");
    customer.deposit(savings, 200);
    customer.withdraw(savings, 500);

    Teller teller("Fatima");
    teller.accessAccount(checking);

    Manager manager("Bilal");
    manager.overrideLimit(checking, 300);

    BankAccount* accounts[] = { &savings, &checking, &business };
    for (auto acc : accounts) {
        acc->endOfMonthProcess();
        acc->display();
    }

    return 0;
}