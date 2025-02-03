#include <iostream>
#include<string>
using namespace std;

int main(int argc, char* argv[]) {
    int sum =0;
    int *ptr = new int;
    for(int i=1; i<argc; i++){
        *ptr = stoi(argv[i]);
        sum += *ptr;
    }
    cout<<"The sum of numbers are: "<<sum<<endl;
    cout<<"The argument count is: "<<argc<<endl;
    delete ptr;
    return 0;
}
