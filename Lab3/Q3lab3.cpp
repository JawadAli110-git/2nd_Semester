#include<iostream>
using namespace std;

class Glass{
    public:
    int liquidLevel = 200;
    void Drink(int mililiters){
       liquidLevel -= mililiters;
    }
    void Refill(){
         liquidLevel = 200;
    }
}Glass;

int main(){
    int miliiters;
    int choice;
     class Glass glass;
    while(1){
        cout<<"1. Want to check liquid level"<<endl;
        cout<<"2. Want to drink"<<endl;
        cout<<"3. Want to refill"<<endl;
        cout<<"4. Exit"<<endl;
        cout << "Enter your choice: ";
        cin>>choice;
        if(choice == 1){
            cout<<"Liquid level is: "<<glass.liquidLevel<<endl;
        }
        if(choice == 2){
            cout<<"Enter mililiters you want to drink: ";
            cin>>miliiters;
            if(miliiters >=1 && miliiters < 200){
                glass.Drink(miliiters);
                cout << "You have " << glass.liquidLevel << " mililiters of liquid left"<<endl;
            }
            else{cout<<"Enter valid amount to drink."<<endl;continue;}
        }
        if(choice == 3){
            if(glass.liquidLevel == 200){
                cout<<"Your glass is already filled!!"<<endl;continue;
            }
            else{
                glass.Refill();
                cout << "Now you have " << glass.liquidLevel << " mililiters of liquid left"<<endl;
            }
        }
        if(choice == 4){break;}
        else{cout<<"Invalid choice"<<endl;continue;}
    }
    return 0;
}