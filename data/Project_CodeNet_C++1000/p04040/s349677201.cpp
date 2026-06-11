#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 200005;
ll h, w, a, b, ans;
ll fac[maxn], facinv[maxn], inv[maxn], mod = 1000000007;

ll c(ll n, ll k)
{
    return (((fac[n] * facinv[k]) % mod) * facinv[n-k]) % mod;
}

int main()
{
    inv[1] = 1;
    for (int i = 2; i <= maxn; i++)
    {
        inv[i] = (mod - (mod / i) * inv[mod % i] % mod) % mod;
    }
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= maxn; i++)
    {
        fac[i] = (i * fac[i-1]) % mod;
    }
    facinv[0] = facinv[1] = 1;
    for (int i = 2; i <= maxn; i++)
    {
        facinv[i] = (inv[i] * facinv[i-1]) % mod;
    }

    cin >> h >> w >> a >> b;
    ans = c(h+w-2, h-1);
    for (ll i = 1; i <= b; i++)
    {
        ans -= (c(h-a+i-2, i-1) * c(a+w-i-1, a-1)) % mod;
        if (ans < 0) ans += mod;
    }
    cout << ans << endl;
    return 0;
}
