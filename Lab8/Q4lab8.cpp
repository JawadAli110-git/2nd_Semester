#include <iostream>

class Number {
private:
    int value;

public:
    Number(int val) : value(val) {}

    // Prefix -- overload (multiplies by 4)
    Number& operator--() {
        value *= 4;
        return *this;
    }

    // Postfix -- overload (divides by 4)
    Number operator--(int) {
        Number temp = *this;
        value /= 4;
        return temp;
    }

    void display() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    Number num(16);
    
    std::cout << "Original: ";
    num.display();
    
    --num;
    std::cout << "After Prefix --: ";
    num.display();
    
    num--;
    std::cout << "After Postfix --: ";
    num.display();
    
    return 0;
}