#include<iostream>
#include<string>
using namespace std;

struct Employee{
    int empId;
    string name;
    int salary;
};
struct Organisation{
    string org_name;
    string org_num;
    Employee emp;
};

int main(){
    Organisation org1;
    cout<<"Enter Oganisation Name: ";
    getline(cin,org1.org_name);
    cout<<"Enter organisation number: ";
    getline(cin,org1.org_num);
    cout<<"Enter employee id: ";
    cin>>org1.emp.empId;
    cin.ignore();
    cout<<"Enter employee name: ";
    getline(cin,org1.emp.name);
    cout<<"Enter employee salary: ";
    cin>>org1.emp.salary;
    cout<<"\n-------x--------x--------x---------\n"<<endl;
    cout<<"The size of structure organisation: "<<sizeof(Organisation)<<endl;
    cout<<"Organisation Name: "<<org1.org_name<<endl;
    cout<<"Organisation Number: "<<org1.org_num<<endl;
    cout<<"Employee id: "<<org1.emp.empId<<endl;
    cout<<"Employee name: "<<org1.emp.name<<endl;
    cout<<"Employee Salary: "<<org1.emp.salary<<endl;

    return 0;
}