#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long k;
    cin >> k;
    long long a = 49 + k / 50;
    int m = (int) (k % 50);
    cout << 50 << endl;
    for (int i = 0; i < 50; i++)
    {
        if (i != 0)
            cout << " ";
        if (i < m)
            cout << a + 50 - (m - 1);
        else
            cout << a - m;
    }
    cout << endl;
    return 0;
}
