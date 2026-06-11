#include <bits/stdc++.h>
using namespace std;
int INF = 1e9+7;
using ll = long long;
int main()
{
    ll a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;
    ll ans = b;
    if(a == 0 || d == 0 || e == 0)
    {
        ans += a / 2 * 2;
        ans += d / 2 * 2;
        ans += e / 2 * 2;
    }
    else
    {
        int ap = a % 2;
        int dp = d % 2;
        int ep = e % 2;
        int sum = ap + dp + ep;
        if(sum % 2 != 0)
        {
            // even :0
            if(ap == 1 && dp == 1 && ep == 1)
            {
                ans += a + d + e;
            }
            // even :2
            else
            {
                ans += a / 2 * 2;
                ans += d / 2 * 2;
                ans += e / 2 * 2;
            }
        }
        else
        {
            // even:3
            if(ap == 0 && dp == 0 && ep == 0)
            {
                ans += a + d + e;
            }
            // even:1
            else
            {
                ans += 3;
                a--;d--;e--;
                ans += a / 2 * 2;
                ans += d / 2 * 2;
                ans += e / 2 * 2;
            }
        }
    }
    cout << ans << endl;
}
