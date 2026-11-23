#include <iostream>
#include <string>
#include <limits>
using namespace std;
class Patient
{
public:
    int id;
    string name;
    int age;
    string disease;
    Patient *next;
    Patient *hashNext;
};
Patient *head = NULL;
const int TABLE_SIZE = 10;
Patient *hashTable[TABLE_SIZE] = {NULL};
int hashFunction(int id)
{
    return id % TABLE_SIZE;
}
void registerPatient()
{
    Patient *newPatient = new Patient();
    cout << "Enter patient ID: ";
    cin >> newPatient->id;
    // Check for duplicate ID
    int index = hashFunction(newPatient->id);
    Patient *temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->id == newPatient->id)
        {
            cout << "Patient ID already exists. Registration failed." << endl;
            delete newPatient;
            return;
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter patient name: ";
    getline(cin, newPatient->name);
    cout << "Enter patient age: ";
    cin >> newPatient->age;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter patient disease: ";
    getline(cin, newPatient->disease);
    // Add patient to the linked list
    newPatient->next = head;
    head = newPatient;
    // Add patient to the hash table
    newPatient->hashNext = hashTable[index];
    hashTable[index] = newPatient;
    cout << "Patient registered successfully." << endl;
}
void searchPatient()
{
    int id;
    cout << "Enter patient ID to search: ";
    cin >> id;
    int index = hashFunction(id);
    Patient *temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "Patient found:" << endl;
            cout << "ID: " << temp->id << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Age: " << temp->age << endl;
            cout << "Disease: " << temp->disease << endl;
            return;
        }
        temp = temp->hashNext;
    }
    cout << "Patient with ID " << id << " not found." << endl;
}
void displayPatient()
{
    Patient *temp = head;
    if (temp == NULL)
    {
        cout << "No patient records available." << endl;
        return;
    }
    cout << "All Patient Records:" << endl;
    while (temp != NULL)
    {
        cout << "ID: " << temp->id << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Age: " << temp->age << endl;
        cout << "Disease: " << temp->disease << endl;
        cout << "-------------------" << endl;
        temp = temp->next;
    }
}
int main()
{
    int choice;
    do
    {
        cout << "Hospital Patient Management System" << endl;
        cout << "1. Register New Patient" << endl;
        cout << "2. Search Patient by ID" << endl;
        cout << "3. Display All Patient Records" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            registerPatient();
            break;
        case 2:
            searchPatient();
            break;
        case 3:
            displayPatient();
            break;
        case 4:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
    return 0;
}
