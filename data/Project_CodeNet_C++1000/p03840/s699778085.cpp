#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    ll a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;
    ll ans = 0;
    ans += b;
    if(a == 0 || d == 0 || e == 0)
    {
        ans += a / 2 * 2;
        ans += d / 2 * 2;
        ans += e / 2 * 2;
        cout << ans << endl;
        return 0;
    }
    if((a % 2 && d % 2) || (a % 2 && e % 2) || (d % 2 && e % 2))
    {
        a -= 1;
        d -= 1;
        e -= 1;
        ans += 3;
    }
    ans += a / 2 * 2;
    ans += d / 2 * 2;
    ans += e / 2 * 2;
    cout << ans << endl;
}
