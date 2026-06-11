#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, i;
    cin >> n >> m;
    long long ans = 0;
    if (m > 2 * n)
    {
        ans += n;
        m -= 2 * n;
    }
    else
    {
        ans += m / 2;
        m = 0;
    }
    ans += m / 4;
    cout << ans << endl;
}