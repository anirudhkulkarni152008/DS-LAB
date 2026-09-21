#include <iostream>
using namespace std;

class StudentSearch
{
public:
    int rno[5];

public:
    StudentSearch()
    {
        cout << "Enter the roll numbers of 5 students:\n";
        for (int i = 0; i < 5; i++)
        {
            cout << "Student " << i + 1 << " Roll No: ";
            cin >> rno[i];
        }
    }

    void searchRollNo()
    {
        int target;
        cout << "\nEnter the roll number you want to search for: ";
        cin >> target;

        bool isFound = false;

        for (int i = 0; i < 5; i++)
        {
            if (rno[i] == target)
            {
                isFound = true;
                break;
            }
        }

        if (isFound)
        {
            cout << "Result: Roll number " << target << " is FOUND.\n";
        }
        else
        {
            cout << "Result: Roll number " << target << " is NOT FOUND.\n";
        }
    }
};

int main()
{

    StudentSearch s1;

    s1.searchRollNo();

    return 0;
}
