#include<iostream>
using namespace std;

class Date{
public:
    int month;
    int day;
    int year;
};

int main(){
    Date date;
    cout<<"Enter the month: ";
    cin>>date.month;
    cout<<"Enter the day: ";
    cin>>date.day;
    cout<<"Enter the year: ";
    cin>>date.year;
    if((date.month>=1 && date.month<=12) && (date.day>=1 && date.day<=31) && (date.year<=2025 && date.year>=1)){
    cout<<"The date is: "<<date.month<<"/"<<date.day<<"/"<<date.year;
    }
    else cout<<"Enter valid date!!";
    return 0;
}