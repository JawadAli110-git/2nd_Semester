#include<iostream>
using namespace std;
class Matrix{
    private:
    int num_rows;
    int num_col;
    int elements[3][3]; 
    
    public:
    Matrix(){
        cout<<"Enter num of rows: ";
        cin>>this->num_rows;

        cout<<"Enter num of columns: ";
        cin>>this->num_col;

        this->elements[this->num_rows][this->num_col];
        for(int i = 0; i<this->num_rows;i++){
            for(int j = 0; j<this->num_col;j++){
                int x;
                cout<<"Enter element at position ["<<i<<"]["<<j<<"] : ";
                cin>>x;
                this->elements[i][j] = x;
            }
        }
    }
    void getRows(){
        cout<<"Number of rows: "<<this->num_rows<<endl;
    }
    void getCol(){
        cout<<"Number of columns: "<<this->num_col<<endl;
    }
    void display(){
        for(int i =0;i<this->num_rows;i++){
            cout<<"[";
            for(int j=0;j < this->num_col;j++){
                cout<<this->elements[i][j]<<" ";
            }
            cout<<"]\n";
        }
    }
};
int main(){

    Matrix m = Matrix();
    m.getRows();
    m.getCol();
    m.display();
    return 0;
}