#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

const int TABLE_SIZE = 10;

class Student
{
public:
    int rollNumber;
    string name;
    vector<string> courses;
    Student *next;
    Student *hashNext;

    Student()
    {
        rollNumber = 0;
        next = NULL;
        hashNext = NULL;
    }
};

Student *head = NULL;
Student *hashTable[TABLE_SIZE] = {};

int hashFunction(int rollNumber)
{
    return rollNumber % TABLE_SIZE;
}

Student *findStudent(int rollNumber)
{
    int index = hashFunction(rollNumber);
    Student *temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->rollNumber == rollNumber)
        {
            return temp;
        }

        temp = temp->hashNext;
    }

    return NULL;
}

void registerStudent()
{
    Student *newStudent = new Student();

    cout << "Enter student roll number: ";
    if (!(cin >> newStudent->rollNumber) || newStudent->rollNumber <= 0)
    {
        cout << "Enter a positive numeric roll number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        delete newStudent;
        return;
    }

    if (findStudent(newStudent->rollNumber) != NULL)
    {
        cout << "Roll number already exists. Registration failed." << endl;
        delete newStudent;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter student name: ";
    getline(cin, newStudent->name);

    newStudent->next = head;
    head = newStudent;

    int index = hashFunction(newStudent->rollNumber);
    newStudent->hashNext = hashTable[index];
    hashTable[index] = newStudent;

    cout << "Student registered successfully." << endl;
}

void searchStudent()
{
    int rollNumber;

    cout << "Enter roll number to search: ";
    if (!(cin >> rollNumber) || rollNumber <= 0)
    {
        cout << "Enter a positive numeric roll number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    Student *student = findStudent(rollNumber);

    if (student == NULL)
    {
        cout << "Student not found." << endl;
        return;
    }

    cout << "Student found:" << endl;
    cout << "Roll Number: " << student->rollNumber << endl;
    cout << "Name: " << student->name << endl;
    cout << "Courses: ";

    if (student->courses.empty())
    {
        cout << "No courses enrolled";
    }
    else
    {
        for (size_t i = 0; i < student->courses.size(); i++)
        {
            cout << student->courses[i];

            if (i < student->courses.size() - 1)
            {
                cout << ", ";
            }
        }
    }

    cout << endl;
}

void updateStudent()
{
    int rollNumber;

    cout << "Enter roll number of the student to update: ";
    if (!(cin >> rollNumber) || rollNumber <= 0)
    {
        cout << "Enter a positive numeric roll number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    Student *student = findStudent(rollNumber);

    if (student == NULL)
    {
        cout << "Student not found." << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter new student name: ";
    getline(cin, student->name);

    cout << "Student information updated successfully." << endl;
}

void enrollStudent()
{
    int rollNumber;

    cout << "Enter student roll number: ";
    if (!(cin >> rollNumber) || rollNumber <= 0)
    {
        cout << "Enter a positive numeric roll number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    Student *student = findStudent(rollNumber);

    if (student == NULL)
    {
        cout << "Student not found." << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string course;
    cout << "Enter course name: ";
    getline(cin, course);

    student->courses.push_back(course);

    cout << "Student enrolled in the course successfully." << endl;
}

void withdrawStudent()
{
    int rollNumber;

    cout << "Enter student roll number: ";
    if (!(cin >> rollNumber) || rollNumber <= 0)
    {
        cout << "Enter a positive numeric roll number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    Student *student = findStudent(rollNumber);

    if (student == NULL)
    {
        cout << "Student not found." << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string course;
    cout << "Enter course name to withdraw from: ";
    getline(cin, course);

    for (size_t i = 0; i < student->courses.size(); i++)
    {
        if (student->courses[i] == course)
        {
            student->courses.erase(student->courses.begin() + i);
            cout << "Student withdrawn from the course successfully." << endl;
            return;
        }
    }

    cout << "This student is not enrolled in that course." << endl;
}

void displayStudents()
{
    Student *temp = head;

    if (temp == NULL)
    {
        cout << "No student records available." << endl;
        return;
    }

    cout << "\nAll Student Records:" << endl;

    while (temp != NULL)
    {
        cout << "Roll Number: " << temp->rollNumber << endl;
        cout << "Name: " << temp->name << endl;
        cout << "Courses: ";

        if (temp->courses.empty())
        {
            cout << "No courses enrolled";
        }
        else
        {
            for (size_t i = 0; i < temp->courses.size(); i++)
            {
                cout << temp->courses[i];

                if (i < temp->courses.size() - 1)
                {
                    cout << ", ";
                }
            }
        }

        cout << endl;
        cout << "-------------------" << endl;

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\nUniversity Student Registration and Course Enrollment System" << endl;
        cout << "1. Register New Student" << endl;
        cout << "2. Search Student by Roll Number" << endl;
        cout << "3. Update Student Information" << endl;
        cout << "4. Enroll Student in a Course" << endl;
        cout << "5. Withdraw Student from a Course" << endl;
        cout << "6. Display All Students" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cout << "Please enter a number from 1 to 7." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice)
        {
        case 1:
            registerStudent();
            break;

        case 2:
            searchStudent();
            break;

        case 3:
            updateStudent();
            break;

        case 4:
            enrollStudent();
            break;

        case 5:
            withdrawStudent();
            break;

        case 6:
            displayStudents();
            break;

        case 7:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
