#include<iostream>
#include<string>
using namespace std;
class Employee{
    private:
    string first_name;
    string last_name;
    double salary;
    public:
    void set(const string& first_name, const string& last_name, double salary){
        this->first_name = first_name;
        this->last_name = last_name;
        if(salary > 0)
        this->salary = salary;
        else this->salary = 0.0;
    }
    void get(){
        cout << "First Name: " << first_name << endl;
        cout << "Last Name: "<<last_name<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
    double yearlySalary(){
        return salary*12;
    }
    void giveRaise(){
        salary += (salary*0.1); 
    }
};
int main(){
    string fname1, lname1, fname2, lname2;
    double sal1, sal2;
    class Employee emp1, emp2;
    //first emplyee
    cout<<"Enter First Name 1: ";
    getline(cin,fname1);
    //cin.ignore();
    cout<<"Enter Last Name 1: ";
    getline(cin,lname1);
    cout<<"Enter your salary 1: ";
    cin>>sal1;
    cin.ignore();

    //second employee
    cout<<"Enter First Name 2: ";
    getline(cin,fname2);
    //cin.ignore();
    cout<<"Enter Last Name 2: ";
    getline(cin,lname2);
    //cin.ignore();
    cout<<"Enter your salary 2: ";
    cin>>sal2;
    cin.ignore();

    //employee 1
    cout<<endl;
    emp1.set(fname1, lname1, sal1);
    emp1.get();
    cout<<"Yearly Salary is: "<<emp1.yearlySalary()<<endl;
    emp1.giveRaise();
    cout<<"After raise yearly Salary is: "<<emp1.yearlySalary()<<endl;;

    //employee 2
    cout<<endl;
    emp2.set(fname2, lname2, sal2);
    emp2.get();
    cout<<"Yearly Salary is: "<<emp2.yearlySalary()<<endl;
    emp2.giveRaise();
    cout<<"After raise yearly Salary is: "<<emp2.yearlySalary()<<endl;

    return 0;
}