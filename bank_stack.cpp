#include <iostream>
using namespace std;
int main()
{
    int stack[5];
    int top = -1;
    int front = 0;
    cout << "ENTER THE TOKEN ID IN ORDER :- " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> stack[++top];
    }
    while (top >= 0)
    {
        cout << "THE TOKEN ID IN ORDER ARE :- " << stack[top] << endl;
        top--;
    }
    return 0;
}
