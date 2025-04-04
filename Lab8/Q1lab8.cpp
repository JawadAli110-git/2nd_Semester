#include <iostream>
#include <algorithm> // For std::gcd (C++17) or __gcd (C++14)
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    // Function to reduce the fraction
    void reduce() {
        int gcd = __gcd(abs(numerator), abs(denominator)); // Use __gcd for GCD calculation
        numerator /= gcd;
        denominator /= gcd;
        
        // Ensure denominator is always positive
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructor
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        reduce();
    }

    // Arithmetic operators
    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, 
                        denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator, 
                        denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw invalid_argument("Cannot divide by zero.");
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    // Relational operators
    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    bool operator<=(const Fraction& other) const {
        return !(*this > other);
    }

    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    // Friend functions for I/O operators
    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& f) {
        char slash;
        is >> f.numerator >> slash >> f.denominator;
        if (f.denominator == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        f.reduce();
        return is;
    }
};

int main() {
    Fraction f1(3, 6), f2(2, 4);
    cout << "Fraction 1: " << f1 << endl;
    cout << "Fraction 2: " << f2 << endl;
    
    cout << "Sum: " << (f1 + f2) << endl;
    cout << "Difference: " << (f1 - f2) << endl;
    cout << "Product: " << (f1 * f2) << endl;
    cout << "Quotient: " << (f1 / f2) << endl;
    
    cout << "f1 == f2? " << (f1 == f2 ? "True" : "False") << endl;
    cout << "f1 > f2? " << (f1 > f2 ? "True" : "False") << endl;
    
    Fraction f3;
    cout << "Enter a fraction (format: a/b): ";
    cin >> f3;
    cout << "You entered: " << f3 << endl;
    
    return 0;
}