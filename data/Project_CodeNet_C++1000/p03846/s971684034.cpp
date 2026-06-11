#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, m, e = 1;
    cin >> n;
    for (int i = 1; i <= n / 2; i++)
    {
        e *= 2;
        e %= 1000000007;
    }
    long long a, d[n];
    for (int i = 0; i < n; i++) d[i] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        d[a]++;
    }
    if (n % 2 == 1)
    {
        m = 0;
        for (int i = 0; i < n; i = i + 2)
        {
            if ((i == 0 && d[i] != 1) || (i > 0 && d[i] != 2))
            {
                m++;
                cout << '0';
                break;
            }
        }
        if (m == 0) cout << e;
    }
    else
    {
        m = 0;
        for (int i = 1; i < n; i = i + 2)
        {
            if (d[i] != 2)
            {
                m++;
                cout << '0';
                break;
            }
        }
        if (m == 0) cout << e;
    }
}