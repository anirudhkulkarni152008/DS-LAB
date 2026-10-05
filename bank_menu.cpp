#include <iostream>
using namespace std;

void bank()
{
    int choice;

    cout << "====BANK SERVICE=====" << endl
         << endl;
    cout << "1] ADD MONEY" << endl
         << endl;
    cout << "2] WITHDRAWAL OF MONEY" << endl
         << endl;
    cout << "3]SHOW THE BALANCE" << endl
         << endl;
    cout << "4] EXIT...THANK YOU FOR VISTING THE BANK" << endl
         << endl;
    cout << "ENTER THE CHOICE :-" << endl
         << endl;
    cin >> choice;

    if (choice == 1)
    {
        cout << " ADD THE MONEY " << endl
             << endl;
        bank();
    }
    else if (choice == 2)
    {
        cout << " WITHDRAW THE MONEY" << endl
             << endl;
        bank();
    }
    else if (choice == 3)
    {
        cout << " THE BANK BALANCE :-  10000000000000000000000" << endl
             << endl;
        bank();
    }
    else if (choice == 4)
    {
        cout << "EXIT.. THANK YOU FOR VISTING THE BANK " << endl
             << endl;
    }
    else
    {
        cout << "INVALID CHOICE...PLS TRY AGAIN....!!!" << endl
             << endl;
        bank();
    }
};

int main()
{
    bank();
    return 0;
}
