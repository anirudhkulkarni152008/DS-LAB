#include <iostream>
using namespace std;

int main()
{
    int queue[5];
    int front = 0;
    int rear = 0;

    cout << "Enter the 5 order nos.:\n";

    for (int i = 0; i < 5; i++)
    {
        cin >> queue[rear];
        rear++;
    }

    cout << "\n THE PROCESSING ORDER NOS ARE:-\n";

    // 2. Dequeue and process all items
    while (front < rear)
    {
        cout << "Processing order no.: " << queue[front] << endl;
        front++;
    }

    return 0;
}
