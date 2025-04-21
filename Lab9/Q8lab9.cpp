#include <iostream>
#include <string>
using namespace std;

// Abstract class
class Student {
public:
    // Pure virtual function
    virtual double getTuition(const string& status, int creditHours) = 0;
    virtual ~Student() {}
};
class GraduateStudent : public Student {
    private:
        string researchTopic;
    
    public:
        // Set research topic
        void setResearchTopic(const string& topic) {
            researchTopic = topic;
        }
    
        // Get research topic
        string getResearchTopic() const {
            return researchTopic;
        }
    
        // Override getTuition
        double getTuition(const string& status, int creditHours) override {
            if (status == "undergraduate")
                return creditHours * 200;
            else if (status == "graduate")
                return creditHours * 300;
            else if (status == "doctoral")
                return creditHours * 400;
            else {
                cout << "Invalid status provided.\n";
                return 0.0;
            }
        }
};
int main() {
    GraduateStudent gs;
    gs.setResearchTopic("Artificial Intelligence in Healthcare");

    string status;
    int creditHours;

    cout << "Enter student status (undergraduate/graduate/doctoral): ";
    cin >> status;
    cout << "Enter number of credit hours: ";
    cin >> creditHours;

    double tuition = gs.getTuition(status, creditHours);

    cout << "\nResearch Topic: " << gs.getResearchTopic() << endl;
    cout << "Tuition for " << status << " with " << creditHours 
         << " credit hours: $" << tuition << endl;

    return 0;
}

    