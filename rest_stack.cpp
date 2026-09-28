#include <iostream>
using namespace std;

int main()
{
    int stack[5];
    int top = -1;
    int front = 0;
    cout << "ENTER FIVE CANCELLED ORDERS" << endl;

    for (int i = 0; i < 5; i++)
    {
        cin >> stack[++top];
        }
    cout << "CANCELLED ORDERS:-" << endl;
    while (top >= 0)
    {
        cout << "PORCESSING CANCLELLED ORDERS:-" << stack[top] << endl;
        top--;
    }
    return 0;
}
