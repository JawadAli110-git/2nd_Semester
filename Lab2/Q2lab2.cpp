#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
void* Add(void* arr, int size, int addvalue){
    int* ptr = (int*)arr;
    for(int i=0; i<size; i++){
        ptr[i] += addvalue;
    }
    return arr;
}
int main(int argc, char* argv[]){
    if(argc < 2){
        cout<<"Please give an argument through command-line: ";
        return 1;
    }
    int size = argc - 1;
    int* arr = new int[size];
    for(int i = 1; i < argc; i++){
        arr[i-1] = atoi(argv[i]);
    }
     int addvalue = 4;
    void* modifiedArr = Add((void*)arr, size, addvalue);
    cout<<"Modified Array: ";
    int* newArr = static_cast<int*>(modifiedArr);
    for(int i=0; i<size; i++){
        cout<<newArr[i]<<" ";
    }
    delete[] arr;

    return 0;
}