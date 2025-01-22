#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main(){
    string movie_name;
    float adult_ticket_price, child_ticket_price, percentage;
    int adult_ticket_sold, child_ticket_sold;
    cout<<"Enter Movie Name: ";
    getline(cin,movie_name);
    cout<<"Enter the price of child ticket: ";
    cin>>child_ticket_price;
    cout<<"Enter the price of adult ticket price: ";
    cin>>adult_ticket_price;
    cout<<"Enter the number of tickets for child: ";
    cin>>child_ticket_sold;
    cout<<"Enter the number of tickets for adult: ";
    cin>>adult_ticket_sold;
    cout<<"Enter the percentage of discount: ";
    cin>>percentage;
    float gross_amount = (child_ticket_price*child_ticket_sold)+(adult_ticket_price*adult_ticket_sold);
    float total_amount = (gross_amount*percentage)/100;
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl;
    cout<<"Movie Name:.............."<<movie_name<<endl;
    cout<<"Number of Tickets Sold:..............."<<child_ticket_sold+adult_ticket_sold<<endl;
    cout<<"Gross Amount:..............$"<<setprecision(3)<<gross_amount<<endl;
    cout<<"Percentage of Gross Amount Donated: "<<setprecision(3)<<percentage<<"%"<<endl;
    cout<<"Amount Donated:..............$"<<setprecision(3)<<total_amount<<endl;
    cout<<"Net Sale:....................$"<<setprecision(3)<<gross_amount-total_amount<<endl;
    
    return 0;
}