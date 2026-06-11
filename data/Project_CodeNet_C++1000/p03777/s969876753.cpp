#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a;
    cin >> a;
    bool key;
    if (a == 'H')
    {
        key = true;
    }
    else
    {
        key = false;
    }
    cin >> a;
    if (key)
    {
        cout << a << endl;
    }
    else
    {
        if (a == 'H')
        {
            cout << 'D' << endl;
        }
        else
        {
            cout << 'H' << endl;
        }
    }
}