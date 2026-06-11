#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, x = 0, y = 0;
    for (int i = 0; i < 3; i++)
    {
        cin >> a;
        if (a == 5)
            x++;
        else if (a == 7)
            y++;
    }
    if (x == 2 && y == 1)
        cout << "YES";
    else
        cout << "NO";
}