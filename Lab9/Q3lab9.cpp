#include <iostream>
#include <string>
using namespace std;

class PatientRecord {
private:
    // Basic Info
    string name;
    int patientID;
    string dateOfBirth;

    // Sensitive Info
    string medicalHistory;
    string currentTreatment;
    string billingInfo;

public:
    PatientRecord(string n, int id, string dob)
        : name(n), patientID(id), dateOfBirth(dob),
          medicalHistory("None"), currentTreatment("None"), billingInfo("Not Generated") {}

    // Public summary info for non-authorized users
    string getPublicData() const {
        return "Name: " + name + ", ID: " + to_string(patientID);
    }

private:
    // Only Doctor can access this
    string getMedicalData() const {
        return "History: " + medicalHistory + ", Treatment: " + currentTreatment;
    }

    void updateMedicalHistory(const string& history, const string& treatment) {
        medicalHistory = history;
        currentTreatment = treatment;
    }

    // Only Billing staff can access this
    void addBillingDetails(const string& billing) {
        billingInfo = billing;
    }

    string getBillingDetails() const {
        return billingInfo;
    }

    // Grant access only to these roles
    friend class Doctor;
    friend class Billing;
};

class Doctor {
public:
    void updatePatientRecord(PatientRecord& record, const string& history, const string& treatment) {
        record.updateMedicalHistory(history, treatment);
    }

    void viewMedicalData(const PatientRecord& record) {
        cout << "[Doctor Access] " << record.getMedicalData() << endl;
    }
};

class Billing {
public:
    void addBill(PatientRecord& record, const string& billingDetails) {
        record.addBillingDetails(billingDetails);
    }

    void viewBill(const PatientRecord& record) {
        cout << "[Billing Access] Bill: " << record.getBillingDetails() << endl;
    }
};

class Receptionist {
public:
    void tryAccessMedicalData(const PatientRecord& record) {
        cout << "[Receptionist Access] " << record.getPublicData() << endl;
        // The line below would cause a compile error if uncommented:
        // cout << record.getMedicalData();
    }
};

int main() {
    PatientRecord patient("Ali Raza", 101, "12-Mar-1998");

    Doctor doc;
    Billing bill;
    Receptionist recep;

    // Doctor updates and views medical data
    doc.updatePatientRecord(patient, "Diabetes", "Insulin shots");
    doc.viewMedicalData(patient);

    // Billing staff adds bill
    bill.addBill(patient, "PKR 12,000 - Insulin course");
    bill.viewBill(patient);

    // Receptionist tries to access
    recep.tryAccessMedicalData(patient);  // Only public info shown

    // Invalid access - Will cause compilation error if uncommented:
    // recep.viewMedicalData(patient);

    return 0;
}
