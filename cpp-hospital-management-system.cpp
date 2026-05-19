#include <iostream>
#include <string>
using namespace std;

class Patient {
private:
    int id;
    string name;
    int age;
    string disease;
    string doctor;
    int days;
    float charges;

public:
    void input() {
        cout << "\n--- Add New Patient ---\n";

        cout << "ID: ";
        cin >> id;
        cin.ignore();

        cout << "Name: ";
        getline(cin, name);

        cout << "Age: ";
        cin >> age;
        cin.ignore();

        cout << "Disease: ";
        getline(cin, disease);

        cout << "Doctor: ";
        getline(cin, doctor);

        cout << "Days Admitted: ";
        cin >> days;

        cout << "Daily Charges: ";
        cin >> charges;
    }

    int getId() {
        return id;
    }

    void display() {
        cout << "\n==============================";
        cout << "\nPatient ID   : " << id;
        cout << "\nName         : " << name;
        cout << "\nAge          : " << age;
        cout << "\nDisease      : " << disease;
        cout << "\nDoctor       : " << doctor;
        cout << "\nDays         : " << days;
        cout << "\nTotal Bill   : " << (days * charges);
        cout << "\n==============================\n";
    }
};

// Database (simple in-memory system)
Patient patients[100];
int totalPatients = 0;

// Add patient
void addPatient() {
    if (totalPatients >= 100) {
        cout << "Database full!\n";
        return;
    }

    patients[totalPatients].input();
    totalPatients++;

    cout << "Patient added successfully!\n";
}

// Show all
void showAll() {
    if (totalPatients == 0) {
        cout << "\nNo records found!\n";
        return;
    }

    for (int i = 0; i < totalPatients; i++) {
        patients[i].display();
    }
}

// Search
void searchPatient() {
    int id;
    cout << "\nEnter Patient ID: ";
    cin >> id;

    for (int i = 0; i < totalPatients; i++) {
        if (patients[i].getId() == id) {
            cout << "\nPatient Found:\n";
            patients[i].display();
            return;
        }
    }

    cout << "Patient not found!\n";
}

// Delete
void deletePatient() {
    int id;
    cout << "\nEnter Patient ID to delete: ";
    cin >> id;

    for (int i = 0; i < totalPatients; i++) {
        if (patients[i].getId() == id) {
            for (int j = i; j < totalPatients - 1; j++) {
                patients[j] = patients[j + 1];
            }
            totalPatients--;
            cout << "Patient deleted successfully!\n";
            return;
        }
    }

    cout << "Patient not found!\n";
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== HOSPITAL MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Patient";
        cout << "\n2. Show All Patients";
        cout << "\n3. Search Patient";
        cout << "\n4. Delete Patient";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addPatient(); break;
            case 2: showAll(); break;
            case 3: searchPatient(); break;
            case 4: deletePatient(); break;
            case 5: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
