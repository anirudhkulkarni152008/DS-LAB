#include <iostream>
using namespace std;

class Student
{
private:
    int rno[5];

public:
    Student()
    {
        cout << "Enter the roll numbers of 5 students:\n";
        for (int i = 0; i < 5; i++)
        {
            cout << "Student " << i + 1 << ": ";
            cin >> rno[i];
        }
    }

    void display()
    {
        cout << "\n--- Displaying Roll Numbers ---\n";
        for (int i = 0; i < 5; i++)
        {
            cout << "Student " << i + 1 << " Roll No: " << rno[i] << "\n";
        }
    }
};

int main()
{
    Student s;
    s.display();
    return 0;
}
