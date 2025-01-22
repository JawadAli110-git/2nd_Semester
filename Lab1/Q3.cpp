#include<iostream>
using namespace std;
int main(){
    int id, units;
    string name;
    float bill, amount=0;
    cin>>id;
    cin>>name;
    cin>>units;
    cout<<"Customer ID: "<<id<<endl;
    cout<<"Customer Name: "<<name<<endl;
    cout<<"Units Consumed: "<<units<<endl;
    if(units > 0 && units <= 199){
        bill = units * 16.20;
        cout<<"Amount Charges @RS. 16.20 per unit: "<<bill<<endl;
        if(bill > 18000){
            amount = bill * 0.15; 
        }
        cout<<"Surcharge Amount: "<<amount<<endl;
        cout<<"Net Amount paid by the Customer: "<<bill + amount; 
    }
    else if(units > 200 && units <= 300){
        bill = units * 20.10;
        cout<<"Amount Charges @RS. 20.10 per unit: "<<bill<<endl;
        if(bill > 18000){
            amount = bill * 0.15; 
        }
        cout<<"Surcharge Amount: "<<amount<<endl;
        cout<<"Net Amount paid by the Customer: "<<bill + amount; 
    }
    else if(units > 300 && units <= 500){
        bill = units * 27.10;
        cout<<"Amount Charges @RS. 27.10 per unit: "<<bill<<endl;
        if(bill > 18000){
            amount = bill * 0.15; 
        }
        cout<<"Surcharge Amount: "<<amount<<endl;
        cout<<"Net Amount paid by the Customer: "<<bill + amount; 
    }
    else if(units > 500){
        bill = units * 35.90;
        cout<<"Amount Charges @RS. 35.90 per unit: "<<bill<<endl;
        if(bill > 18000){
            amount = bill * 0.15; 
        }
        cout<<"Surcharge Amount: "<<amount<<endl;
        cout<<"Net Amount paid by the Customer: "<<bill + amount; 
    }
    else {
        cout<<"Invalid Input";
    }

    return 0;
}