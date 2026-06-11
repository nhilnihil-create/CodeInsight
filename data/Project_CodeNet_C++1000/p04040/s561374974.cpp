#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;
const int N = 2e5 + 5;
const ll MOD = 1e9 + 7;

int n, m, a, b;

ll pw(ll x, ll e)
{
    if(e == 0)
        return 1LL;
    if(e == 1)
        return x;

    ll res = pw(x, e / 2);
    res = (res * res) % MOD;
    if(e & 1)
        res = (res * x) % MOD;
    return res;
}

ll f[N], inv_f[N];
ll choose(int x, int y)
{
    if(y > x)
        return 0;
    ll res = (((f[x] * inv_f[y]) % MOD) * inv_f[x - y]) % MOD;
    return res;
}

ll ans;
ll ways_small[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> a >> b;

    f[0] = 1;
    for(int i = 1; i < N; i++)
        f[i] = (f[i - 1] * i) % MOD;
    inv_f[N - 1] = pw(f[N - 1], MOD - 2);
    for(int i = N - 2; i >= 0; i--)
        inv_f[i] = (inv_f[i + 1] * (i + 1)) % MOD;

    ans = choose(n + m - 2, n - 1);
    for(int i = 1; i <= b; i++)
    {
        ll cur = (choose((n - a) + i - 2, i - 1) * choose((m - i + 1) + a - 2, a - 1)) % MOD;
        ans = ((ans - cur) + MOD) % MOD;
    }

    cout << ans << endl;

    return 0;
}
