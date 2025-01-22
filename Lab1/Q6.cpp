#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main(){
    int scores[5];
    string name;
    getline(cin,name);
    cout<<"Enter the scores: "<<endl;
    for(int i=0; i<5; i++){
        cin>>scores[i];
    }
    float avg_score, sum;
    for(int i=0; i<5; i++){
        sum += scores[i];
    }
    avg_score = sum/5;
    cout<<"Student Name: "<<name<<endl;
    cout<<"Test Scores: ";
    for(int i=0; i<5; i++){
        cout<<scores[i]<<" ";
    }
    cout<<endl;
    cout<<"Average test score: "<<setprecision(3)<<avg_score;

    return 0;
}