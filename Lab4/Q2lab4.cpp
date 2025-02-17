#include<iostream>
using namespace std;

class Account{
    private:
        double acc_bal;
    public:
    //Making Bank Account and intialization through constructer
        Account(double initial_bal){
            if(initial_bal >=0){
                acc_bal = initial_bal;
            }
            else{
                acc_bal = 0.0;
            }
        }

        void credit(double amount){
            if(amount >= 0){
            acc_bal += amount;
            cout<<"The amount entered is: "<<amount<<endl;
            cout<<"Current amount updated to: "<<acc_bal<<endl;
            }
            else{
                acc_bal += 0.0;
                cout<<"You entered a negative amount!!"<<endl;
            }
        }

        void debit(double amount){
            if(amount <= acc_bal && amount >= 0){
                acc_bal -= amount;
                cout<<"The amount entered is: "<<amount<<endl;
                cout<<"Current amount updated to: "<<acc_bal<<endl;
            }
            else{
                acc_bal -= 0.0;
                cout<<"You entered a negative amount OR insufficient amount!!"<<endl;
            }
        }
};

int main(){
    Account a(677.757);
    a.credit(1000);
    a.debit(500);

    return 0;
}