#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
bool chmax(t &a, u b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class t, class u>
bool chmin(t &a, u b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}

ll mod = 1000000007;

ll factormod(ll a)
{
    if (a == 1)
    {
        return 1;
    }
    else
    {
        return a * factormod(a - 1) % mod;
    }
}

signed main()
{
    ll n, m;
    cin >> n >> m;
    ll ans;
    if (n == m)
    {
        ans = (2 * factormod(n) % mod) * factormod(m) % mod;
    }
    else if (n == m + 1 || n + 1 == m)
    {
        ans = factormod(n) * factormod(m) % mod;
    }
    else
    {
        ans = 0;
    }
    printf("%lld\n", ans);

    return 0;
}