#include<iostream>
using namespace std;
int* resizeArr(int*arr, int& cap, int size){
    int* newarr = new int[size];
    for(int i=0; i<size; i++){
        newarr[i] = arr[i];
    }
    cap = size;
    delete[] arr;
    return newarr;
}

int main(){
    int cap = 5;
    int* arr = new int[cap];
    int size = 0;
    int value;
    while(1){
        cout << "Enter a value to add to the array (or -1 to stop): ";
        cin>>value;
        if(value == -1){
            break;
        }
        if(size >= cap){
            arr = resizeArr(arr, cap, cap*2);
            cout<<"The array is resized to: "<<cap<<endl;
        }
        arr[size++] = value;
    }
    arr = resizeArr(arr, cap, size);
    cout<<"The array is resized to: "<<size<<endl;

    cout<<"The elements of array are: ";
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    delete[] arr;

    return 0;
}