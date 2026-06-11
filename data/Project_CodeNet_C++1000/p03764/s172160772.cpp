#include <bits/stdc++.h>
#define ll long long
using namespace std;
ifstream fi("input.in");

const ll MOD = 1000000007;

ll n, m;
ll sx, sy;
ll x[100005], y[100005];
signed main()
{
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
        cin >> x[i];
    for (ll i = 1; i <= m; i++)
        cin >> y[i];

    for (ll i = 1; i <= n; i++)
        sx = (sx + 1LL * (i - 1) * x[i] % MOD - 1LL * (n - i) * x[i] % MOD + MOD) % MOD;
    for (ll i = 1; i <= m; i++)
        sy = (sy + 1LL * (i - 1) * y[i] % MOD - 1LL * (m - i) * y[i] % MOD + MOD) % MOD;

    cout << sx * sy % MOD;
    return 0;
}
