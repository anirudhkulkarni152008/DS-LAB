#include <iostream>
using namespace std;
int main()
{
    int queue[50];
    int front = 0;
    int rear = 0;

    cout << "ENTER THE TOKEN ID IN ORDER :- " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> queue[rear];
        rear++;
    }
    while (front < rear)
    {
        cout << "THE TOKEN ID IN ORDER ARE :- " << queue[front] << endl;
        front++;
    }
    return 0;
}
