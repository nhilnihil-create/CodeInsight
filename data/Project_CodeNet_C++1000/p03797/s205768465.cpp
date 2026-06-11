#include <bits/stdc++.h>
using namespace std;
int main()
{
    long n, m, ans = 0;
    cin >> n >> m;
    if (n >= m / 2)
    {
        ans += m / 2;
        m -= ans * 2;
    }
    else
    {
        ans += n;
        m -= ans * 2;
    }
    ans += m / 4;

    cout << ans << endl;

    return 0;
}