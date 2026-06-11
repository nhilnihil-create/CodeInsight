#include <bits/stdc++.h>

using namespace std;
int main()
{
    int w, a, b;
    cin >> w >> a >> b;
    if (a < b)
    {
        if (b - a - w > 0)
        {
            cout << b - a - w << endl;
            return 0;
        }
        else
        {
            cout << "0" << endl;
        }
    }
    else if (b < a)
    {
        if (a - b - w > 0)
        {
            cout << a - b - w << endl;
            return 0;
        }
        else
        {
            cout << "0" << endl;
        }
    }
    else
    {
        cout << "0" << endl;
    }

    return 0;
}