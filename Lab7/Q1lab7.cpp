#include <iostream>
#include <vector>
using namespace std;

// Base Class: Account
class Account {
protected:
    int accountNumber;
    float balance;
    string accountHolderName;
    string accountType;
    vector<float> withdrawals;
    vector<float> deposits;

public:
    Account(int num, float bal, string name, string type)
        : accountNumber(num), balance(bal), accountHolderName(name), accountType(type) {}

    virtual void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            deposits.push_back(amount);
            cout << "Deposited: " << amount << " | New Balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    virtual void withdraw(float amount) {
        if (balance >= amount && amount > 0) {
            balance -= amount;
            withdrawals.push_back(amount);
            cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
        } else {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }

    virtual void calculateInterest() {
        cout << "Interest calculation varies by account type." << endl;
    }

    virtual void printStatement() {
        cout << "\n===== Account Statement =====\n";
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Withdrawals: ";
        for (float w : withdrawals) cout << w << " ";
        cout << "\nDeposits: ";
        for (float d : deposits) cout << d << " ";
        cout << "\n===========================\n";
    }

    virtual void getAccountInfo() {
        cout << "\n===== Account Info =====\n";
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Current Balance: " << balance << endl;
    }

    virtual ~Account() {} // Virtual destructor
};

// Derived Class: SavingsAccount
class SavingsAccount : public Account {
private:
    float interestRate;
    float minimumBalance;

public:
    SavingsAccount(int num, float bal, string name, float rate, float minBal)
        : Account(num, bal, name, "Savings"), interestRate(rate), minimumBalance(minBal) {}

    void calculateInterest() override {
        if (balance >= minimumBalance) {
            float interest = balance * (interestRate / 100);
            balance += interest;
            cout << "Interest Added: " << interest << " | New Balance: " << balance << endl;
        } else {
            cout << "Balance below minimum. No interest applied." << endl;
        }
    }

    void withdraw(float amount) override {
        if ((balance - amount) >= minimumBalance && amount > 0) {
            balance -= amount;
            withdrawals.push_back(amount);
            cout << "Withdrawn: " << amount << " | New Balance: " << balance << endl;
        } else {
            cout << "Cannot withdraw. Minimum balance must be maintained." << endl;
        }
    }
};

// Derived Class: FixedDepositAccount
class FixedDepositAccount : public Account {
private:
    int maturityDate;
    float fixedInterestRate;

public:
    FixedDepositAccount(int num, float bal, string name, int maturity, float rate)
        : Account(num, bal, name, "Fixed Deposit"), maturityDate(maturity), fixedInterestRate(rate) {}

    void calculateInterest() override {
        float interest = balance * (fixedInterestRate / 100);
        cout << "Fixed Interest: " << interest << " (will be applied at maturity)" << endl;
    }
};

// Main Function
template <typename T>
void testAccount(T &acc) {
    acc.getAccountInfo();
    acc.deposit(500);
    acc.calculateInterest();
    acc.withdraw(200);
    acc.printStatement();
}

int main() {
    SavingsAccount sa(101, 1000, "Alice", 5.0, 500);
    FixedDepositAccount fda(102, 5000, "Bob", 12, 7.0);

    cout << "\nTesting Savings Account:\n";
    testAccount(sa);

    cout << "\nTesting Fixed Deposit Account:\n";
    testAccount(fda);

    return 0;
}
