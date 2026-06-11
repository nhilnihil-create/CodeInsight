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

ll mypow(ll x, ll y)
{
    ll ret = 1;
    rep(i, y)
    {
        ret *= x;
    }
    return ret;
}

signed main()
{
    int n, p;
    cin >> n >> p;
    vi cnt(2);
    rep(i, n)
    {
        int a;
        cin >> a;
        if (a % 2 == 0)
        {
            cnt[0]++;
        }
        else
        {
            cnt[1]++;
        }
    }
    ll ans = 0;
    if (cnt[1] == 0)
    {
        if (p == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            printf("%lld\n", mypow(2, n));
        }
    }
    else
    {
        printf("%lld\n", mypow(2, n - 1));
    }
    return 0;
}