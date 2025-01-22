#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    float weight_kg,weight_lb;
    cout<<"Enter the weight in kilogram: ";
    cin>>weight_kg;
    weight_lb = weight_kg * 2.20462;
    cout<<"Weight in kilograms: "<<setprecision(3)<<weight_kg<<endl;
    cout<<"Weight in pounds: "<<setprecision(3)<<weight_lb<<endl;

    return 0;
}