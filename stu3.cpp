#include <iostream>
using namespace std;
int main()
{
    int student[5];
    int searchRno;

    cout << "enter 5 student marks.:-" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> student[i];
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (student[j] < student[j + 1])
            {
                int temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }
    cout << "Sorted student roll no.: ";
    for (int i = 0; i < 5; i++)
    {
        cout << student[i] << " ";
    }
    cout << endl;
    return 0;
}
