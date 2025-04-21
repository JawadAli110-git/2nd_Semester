#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    int bookedSeats = 0;

    // Set to store booked passenger IDs
    unordered_set<int> bookedPassengers;

public:
    Flight(string number, string dep, string arr, int cap)
        : flightNumber(number), departure(dep), arrival(arr), capacity(cap) {}

    string getFlightDetails() const {
        return "Flight: " + flightNumber + ", " + departure + " → " + arrival + 
               ", Seats: " + to_string(bookedSeats) + "/" + to_string(capacity);
    }

    bool bookSeat(int passengerID) {
        if (bookedSeats >= capacity) {
            cout << "❌ Booking failed: No seats available.\n";
            return false;
        }
        if (bookedPassengers.count(passengerID)) {
            cout << "⚠️ Already booked.\n";
            return false;
        }
        bookedPassengers.insert(passengerID);
        bookedSeats++;
        cout << "✅ Seat booked for Passenger ID " << passengerID << endl;
        return true;
    }

    bool cancelSeat(int passengerID) {
        if (!bookedPassengers.count(passengerID)) {
            cout << "❌ Cancellation failed: No booking found.\n";
            return false;
        }
        bookedPassengers.erase(passengerID);
        bookedSeats--;
        cout << "✅ Booking canceled for Passenger ID " << passengerID << endl;
        return true;
    }

    bool upgradeSeat(int passengerID) {
        if (!bookedPassengers.count(passengerID)) {
            cout << "❌ Upgrade failed: No booking found.\n";
            return false;
        }
        cout << "✨ Seat upgraded for Passenger ID " << passengerID << endl;
        return true;
    }
};

class Passenger {
private:
    int id;
    string name;

public:
    Passenger(int id_, string name_) : id(id_), name(name_) {}

    void requestBooking(Flight& flight) {
        cout << "\n[" << name << "] Booking request...\n";
        flight.bookSeat(id);
    }

    void requestCancellation(Flight& flight) {
        cout << "\n[" << name << "] Cancellation request...\n";
        flight.cancelSeat(id);
    }

    void requestUpgrade(Flight& flight) {
        cout << "\n[" << name << "] Upgrade request...\n";
        flight.upgradeSeat(id);
    }
};
int main() {
    Flight flight1("PK101", "Karachi", "Lahore", 2);
    Passenger p1(1, "Ali");
    Passenger p2(2, "Sara");
    Passenger p3(3, "Hamza");

    cout << flight1.getFlightDetails() << endl;

    p1.requestBooking(flight1);
    p2.requestBooking(flight1);
    p3.requestBooking(flight1);  // Exceeds capacity

    cout << "\n" << flight1.getFlightDetails() << endl;

    p1.requestUpgrade(flight1);
    p3.requestUpgrade(flight1);  // Not booked

    p1.requestCancellation(flight1);
    p1.requestCancellation(flight1);  // Already canceled

    cout << "\n" << flight1.getFlightDetails() << endl;

    return 0;
}
