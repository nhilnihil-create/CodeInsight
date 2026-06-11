#include <bits/stdc++.h>
using namespace std;

const int maxhplusw = 2e5 + 5, MOD = 1e9 + 7;

int h, w, a, b, fact[maxhplusw], invfact[maxhplusw];

int mod_expo(int x, int p)
{
    if(!p)
        return 1;
    long long res = mod_expo(x, p / 2);
    res *= res;
    res %= MOD;
    if(p & 1)
        res *= x;
    return res % MOD;
}

int mod_inv(int x)
{
    return mod_expo(x, MOD - 2);
}

int nCr_mod(int n, int r)
{
    if(n < r)
        return 0;
    int num = fact[n];
    int invdenom = (invfact[r] * 1ll * invfact[n - r]) % MOD;
    return (num * 1ll * invdenom) % MOD;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fact[0] = invfact[0] = 1;
    for(int i = 1; i < maxhplusw; i++)
    {
        fact[i] = (fact[i - 1] * 1ll * i) % MOD;
        invfact[i] = mod_inv(fact[i]);
    }
    cin >> h >> w >> a >> b;
    long long ans = 0;
    int up = h - a - 1; // Number of steps down to just above blocked area
    int down = a - 1;   // Number of steps down from row at top of blocked area
    for(int i = b + 1; i <= w; i++)
    {
        int upper = nCr_mod(up + (i - 1), up);
        int lower = nCr_mod(down + (w - i), down);
        ans += (upper * 1ll * lower) % MOD;
        ans %= MOD;
    }
    cout << ans << "\n";
    return 0;
}