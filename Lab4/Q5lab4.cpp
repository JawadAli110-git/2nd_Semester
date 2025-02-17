#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Class representing a menu item
class MenuItem {
public:
    string name;
    string type; // "food" or "drink"
    double price;

    // Constructor
    MenuItem(string n, string t, double p) : name(n), type(t), price(p) {}
};

// Class representing a coffee shop
class CoffeeShop {
private:
    string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    // Constructor
    CoffeeShop(string n, vector<MenuItem> m) : name(n), menu(m) {}

    // Method to add an order
    string addOrder(string itemName) {
        for (const MenuItem& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return itemName + " added to orders!";
            }
        }
        return "This item is currently unavailable.";
    }

    // Method to fulfill an order
    string fulfillOrder() {
        if (!orders.empty()) {
            string item = orders.front(); // Get the first order
            orders.erase(orders.begin()); // Remove it from the orders list
            return "The " + item + " is ready.";
        } else {
            return "All orders have been fulfilled.";
        }
    }

    // Method to list all orders
    vector<string> listOrders() {
        return orders;
    }

    // Method to calculate the total amount due
    double dueAmount() {
        double total = 0.0;
        for (const string& order : orders) {
            for (const MenuItem& item : menu) {
                if (item.name == order) {
                    total += item.price;
                    break;
                }
            }
        }
        return total;
    }

    // Method to find the cheapest item on the menu
    string cheapestItem() {
        if (menu.empty()) return "No items available.";
        MenuItem cheapest = menu[0];
        for (const MenuItem& item : menu) {
            if (item.price < cheapest.price) {
                cheapest = item;
            }
        }
        return cheapest.name;
    }

    // Method to return only drink items
    vector<string> drinksOnly() {
        vector<string> drinks;
        for (const MenuItem& item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    // Method to return only food items
    vector<string> foodOnly() {
        vector<string> foods;
        for (const MenuItem& item : menu) {
            if (item.type == "food") {
                foods.push_back(item.name);
            }
        }
        return foods;
    }
};

int main() {
    // Create a menu
    vector<MenuItem> menu = {
        MenuItem("Coffee", "drink", 3.50),
        MenuItem("Tea", "drink", 2.50),
        MenuItem("Sandwich", "food", 5.00),
        MenuItem("Cake", "food", 4.00)
    };

    // Create a coffee shop
    CoffeeShop shop("My Coffee Shop", menu);

    // Test the methods
    cout << shop.addOrder("Coffee") << endl; // Add an available item
    cout << shop.addOrder("Burger") << endl; // Add an unavailable item

    cout << shop.fulfillOrder() << endl; // Fulfill the first order
    cout << shop.fulfillOrder() << endl; // Try to fulfill when no orders are left

    cout << "Orders: ";
    for (const string& order : shop.listOrders()) {
        cout << order << " ";
    }
    cout << endl;

    cout << "Total due amount: $" << shop.dueAmount() << endl;

    cout << "Cheapest item: " << shop.cheapestItem() << endl;

    cout << "Drinks: ";
    for (const string& drink : shop.drinksOnly()) {
        cout << drink << " ";
    }
    cout << endl;

    cout << "Foods: ";
    for (const string& food : shop.foodOnly()) {
        cout << food << " ";
    }
    cout << endl;

    return 0;
}