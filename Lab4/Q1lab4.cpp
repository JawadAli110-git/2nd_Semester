#include<iostream>
using namespace std;
class Circle{
    private:
        float radius;
        const double PI = 3.141592653;
    public:
    Circle(float r){radius = r;}

    float getArea(){
        return PI * radius * radius;
    }

    float getPerimeter(){
        return 2 * PI * radius;
    }
};

int main(){
    Circle c(5.0);
    cout<<"Area: "<<c.getArea()<<endl;
    cout<<"Perimeter: "<<c.getPerimeter()<<endl;


    return 0;
}