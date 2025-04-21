#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class Car {
protected:
    string model;
    double price;

public:
    void setModel(const string& m) { model = m; }
    string getModel() const { return model; }

    double getPrice() const { return price; }

    // Abstract method
    virtual void setPrice(double p) = 0;

    // Virtual destructor
    virtual ~Car() {}
};

// Derived Class: Color
class Color : public Car {
private:
    string color;
public:
    void setColor(const string& c) { color = c; }
    string getColor() const { return color; }

    // Implement abstract setPrice()
    void setPrice(double p) override {
        price = p + 5000;  // e.g. color adds 5000
    }

    void display() {
        cout << "Car Model: " << model << ", Color: " << color
             << ", Price: " << price << endl;
    }
};

// Derived Class: Company
class Company : public Car {
private:
    string company;
public:
    void setCompany(const string& c) { company = c; }
    string getCompany() const { return company; }

    // Implement abstract setPrice()
    void setPrice(double p) override {
        price = p + 10000;  // e.g. brand value adds 10000
    }

    void display() {
        cout << "Car Model: " << model << ", Company: " << company
             << ", Price: " << price << endl;
    }
};
int main() {
    Color car1;
    car1.setModel("Civic");
    car1.setColor("Red");
    car1.setPrice(2000000);  // Base price + color cost
    car1.display();

    Company car2;
    car2.setModel("Corolla");
    car2.setCompany("Toyota");
    car2.setPrice(1800000);  // Base price + company value
    car2.display();

    return 0;
}
