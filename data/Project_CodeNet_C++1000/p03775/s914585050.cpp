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

//ll mod = 1000000007;
ll mod = 998244353;

signed main()
{
    ll n;
    ll ans = 100000;
    auto f = [](ll x) {
        ll a = 0;
        while (x > 0)
        {
            x /= 10;
            a++;
        }
        return a;
    };
    cin >> n;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll j = n / i;
            chmin(ans, max(f(i), f(j)));
        }
    }
    cout << ans << endl;
    return 0;
}