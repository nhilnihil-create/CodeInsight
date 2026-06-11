#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w, a, b;
    cin >> w >> a >> b;
    if (b > a + w || b + w < a)
    {
        if (a > b)
        {
            cout << a - b - w << endl;
        }
        else
        {
            cout << b - a - w << endl;
        }
    }
    else
    {
        cout << 0 << endl;
    }
}