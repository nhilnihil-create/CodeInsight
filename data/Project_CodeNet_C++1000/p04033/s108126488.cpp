// https://atcoder.jp/contests/agc002/tasks/agc002_a

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long a, b;
    cin >> a >> b;

    if (a > 0)
    {
        cout << "Positive" << endl;
    }
    else if (a == 0)
    {
        cout << "Zero" << endl;
    }
    else
    {
        if (b >= 0)
        {
            cout << "Zero" << endl;
        }
        else
        {
            cout << ((b - a + 1) & 1 ? "Negative" : "Positive") << endl;
        }
    }
    return 0;
}
