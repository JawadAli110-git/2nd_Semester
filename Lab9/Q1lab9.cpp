#include<iostream>
using namespace std;
class Wallet{
    private:
        double balance;
        static double transaction_limits;
    public:
        Wallet(double bal) : balance(bal) {
            cout << "Wallet opened." << endl;
        }
        void deposit(double amount){
            if(amount > 0 && transaction_limits < 10){
                balance += amount;
                transaction_limits++;
                cout << "YOUR CURRENT BALANCE: " << balance << endl;
            }
            else cout << "Invalid amount." << endl;
        }
        virtual void showDetails() = 0;
        void withdraw(double amount){
            if (amount <= balance && transaction_limits < 10) {
                transaction_limits++;
                balance -= amount;
                cout << "YOUR CURRENT BALANCE: " << balance << endl;
            }
            else cout << "Invalid amount" << endl;
        }
        double getBal(){
            return balance;
        }
        void resetLimit(){
            transaction_limits = 0;
        }
        ~Wallet(){
            cout << "Wallet closed." << endl;
        }
};
double Wallet::transaction_limits = 0;
class User : public Wallet{
    private:
        int userID;
        string name;
    public:
        User(double bal, int id, string n) : Wallet(bal), userID(id), name(n) {cout << "User opened the Wallet." << endl;}
        void showDetails() override {
            cout << "User ID: " << userID << endl;
            cout << "User Name: " << name << endl;
            cout << "Current Balance: " << getBal() << endl;
        }
        ~User(){
            cout << "User closed the Wallet." << endl;
        }
};
int main(){
    User u1(1000.0, 1, "John");
    User u2(2000.0, 2, "Jack");
    u1.deposit(5000.0);
    u1.withdraw(1000.0);
    u1.showDetails();
    u2.deposit(5000.0);
    u2.withdraw(2000.0);
    u2.showDetails();

    return 0;
}