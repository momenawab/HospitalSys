#include <iostream>
#include <string>

using namespace std;

struct Patient {
    int ID;
    string Name;
    string Branch;  // Changed from Address to Branch
    string Appointment;
    Patient* next;
};

void addPatient(Patient*& head, int id, const string& name, const string& branch, const string& appointment) {
    Patient* newPatient = new Patient;
    newPatient->ID = id;
    newPatient->Name = name;
    newPatient->Branch = branch;
    newPatient->Appointment = appointment;
    newPatient->next = head;
    head = newPatient;
    cout << "Patient added successfully.\n";
}

void removePatient(Patient*& head, int id) {
    Patient* current = head;
    Patient* previous = nullptr;

    while (current != nullptr && current->ID != id) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Patient with ID " << id << " not found.\n";
        return;
    }

    if (previous == nullptr) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    delete current;
    cout << "Patient with ID " << id << " removed successfully.\n";
}

void bookAppointment(Patient* head, int id, const string& newAppointment) {
    Patient* current = head;

    while (current != nullptr && current->ID != id) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Patient with ID " << id << " not found.\n";
        return;
    }

    current->Appointment = newAppointment;
    cout << "Appointment booked successfully for patient with ID " << id << ".\n";
}

void searchPatientByName(Patient* head, const string& name) {
    Patient* current = head;
    bool found = false;

    while (current != nullptr) {
        if (current->Name == name) {
            found = true;
            cout << "Patient found:\n";
            cout << "ID: " << current->ID << "\n";
            cout << "Name: " << current->Name << "\n";
            cout << "Branch: " << current->Branch << "\n";  // Changed from Address to Branch
            cout << "Appointment: " << current->Appointment << "\n";
            break;
        }
        current = current->next;
    }

    if (!found) {
        cout << "Patient with name " << name << " not found.\n";
    }
}

void updatePatientInfo(Patient* head, int id, const string& newBranch, const string& newAppointment) {
    Patient* current = head;

    while (current != nullptr && current->ID != id) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Patient with ID " << id << " not found.\n";
        return;
    }

    current->Branch = newBranch;  // Changed from Address to Branch
    current->Appointment = newAppointment;
    cout << "Patient information updated successfully for ID " << id << ".\n";
}

void displayPatients(Patient* head) {
    Patient* current = head;

    cout << "List of Patients:\n";
    while (current != nullptr) {
        cout << "ID: " << current->ID << ", "<<endl;
        cout << "Name: " << current->Name << ", "<<endl;
        cout << "Branch: " << current->Branch << ", "<<endl;  // Changed from Address to Branch
        cout << "Appointment: " << current->Appointment <<endl;
        current = current->next;
    }
    cout << endl;
}

int main() {
    Patient* patientsList = nullptr;

    char choice;
    do {
        cout << "Choose an option:\n";
        cout << "a. Add new patient\n";
        cout << "b. Remove a patient\n";
        cout << "c. Book Appointment\n";
        cout << "d. Search for patient by Name\n";
        cout << "e. Update patient Information\n";
        cout << "f. Display Patients\n";
        cout << "g. Quit\n";

        cin >> choice;

        switch (choice) {
            case 'a':
            {
                int id;
                string name, branch, appointment;
                cout << "Enter patient ID: ";
                cin >> id;
                cout << "Enter patient name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter patient branch: ";
                getline(cin, branch);  // Changed from Address to Branch
                cout << "Enter appointment: ";
                getline(cin, appointment);
                addPatient(patientsList, id, name, branch, appointment);
                break;
            }
            case 'b':
            {
                int id;
                cout << "Enter patient ID to remove: ";
                cin >> id;
                removePatient(patientsList, id);
                break;
            }
            case 'c':
            {
                int id;
                string newAppointment;
                cout << "Enter patient ID for appointment booking: ";
                cin >> id;
                cout << "Enter new appointment: ";
                cin.ignore();
                getline(cin, newAppointment);
                bookAppointment(patientsList, id, newAppointment);
                break;
            }
            case 'd':
            {
                string name;
                cout << "Enter patient name to search: ";
                cin.ignore();
                getline(cin, name);
                searchPatientByName(patientsList, name);
                break;
            }
            case 'e':
            {
                int id;
                string newBranch, newAppointment;
                cout << "Enter patient ID to update: ";
                cin >> id;
                cout << "Enter new branch: ";
                cin.ignore();
                getline(cin, newBranch);  // Changed from Address to Branch
                cout << "Enter new appointment: ";
                getline(cin, newAppointment);
                updatePatientInfo(patientsList, id, newBranch, newAppointment);
                break;
            }
            case 'f':
                displayPatients(patientsList);
                break;
            case 'g':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 'g');

    return 0;
}