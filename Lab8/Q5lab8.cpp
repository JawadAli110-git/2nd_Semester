#include <iostream>

class Shape {
private:
    double area;

public:
    Shape(double a = 0) : area(a) {}
    
    // Overloading + operator to add areas of two shapes
    Shape operator+(const Shape& other) const {
        return Shape(this->area + other.area);
    }
    
    void display() const {
        std::cout << "Area: " << area << " sq. units" << std::endl;
    }
};

int main() {
    Shape shape1(25.5), shape2(40.2);
    
    std::cout << "Shape1: ";
    shape1.display();
    
    std::cout << "Shape2: ";
    shape2.display();
    
    Shape totalArea = shape1 + shape2;
    
    std::cout << "Total Area: ";
    totalArea.display();
    
    return 0;
}
