// https://atcoder.jp/contests/abc059/tasks/abc059_b

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    if (a.size() < b.size())
    {
        cout << "LESS" << endl;
        return 0;
    }

    if (a.size() == b.size())
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] < b[i])
            {
                cout << "LESS" << endl;
                return 0;
            }
            else if (a[i] > b[i])
            {
                cout << "GREATER" << endl;
                return 0;
            }
        }
        cout << "EQUAL" << endl;
        return 0;
    }

    if (a.size() > b.size())
    {
        cout << "GREATER" << endl;
        return 0;
    }
}
