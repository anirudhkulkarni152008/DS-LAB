#include <iostream>
using namespace std;

void menu()
{
    int choice;
    cout << "======= restro menu=======" << endl;
    cout << "1] PIZZA" << endl;
    cout << "2] BURGER" << endl;
    cout << "3] PASTA" << endl;
    cout << "4] COFFEE" << endl;
    cout << "5] EXIT" << endl;

    cout << "ENTER THE CHOICE  :-" << endl;
    cin >> choice;

    if (choice == 1)
    {
        cout << "SELECTED ITEM IS PIZZA" << endl<< endl;
        menu();
    }
    else if (choice == 2)
    {
        cout << "SELECTED ITEM IS BURGER" << endl<< endl;
        menu();
    }
    else if (choice == 3)
    {
        cout << "SELECTED ITEM IS PASTA" << endl<< endl;
        menu();
    }
    else if (choice == 4)
    {
        cout << "SELECTED ITEM IS COFFEE" << endl<< endl;
        menu();
    }
    else if (choice == 5)
    {
        cout << "THANK YOU FOR VISITING THE RESTAURANT." << endl<< endl;
    }
    else
    {
        cout << "INVALID CHOICE. PLEASE TRY AGAIN." << endl<< endl;
        menu();
    }
}
int main()
{
    menu();
    return 0;
}
