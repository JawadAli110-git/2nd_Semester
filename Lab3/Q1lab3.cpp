#include<iostream>
#include<string>
using namespace std;

class User{
public:
    int age;
    string name;
};
int main(){
    User p;
    cout<<"Enter your Name: ";
    getline(cin,p.name);
    cout<<"Enter you age: ";
    cin>>p.age;

    cout<<"My Name is "<<p.name<<" and I'm "<<p.age<<"years old";
    return 0;
}