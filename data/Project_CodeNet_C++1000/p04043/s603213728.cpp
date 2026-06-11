#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int counter = 0;
    int down = 2;
    int a;
    for (int i = 0; i < 3; i++)
    {
        cin >> a;
        if (a == 5)
        {
            counter++;
            down--;
        }
        if (a == 7)
            counter++;
    }
    if (counter == 3 && down == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}