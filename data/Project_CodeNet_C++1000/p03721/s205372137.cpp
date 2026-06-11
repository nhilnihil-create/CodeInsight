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

signed main()
{
    ll n, k;
    cin >> n >> k;
    map<int, ll> m;
    rep(i, n)
    {
        int a, b;
        cin >> a >> b;
        m[a] += b;
    }
    ll sum = 0;
    int ans = 0;
    for (auto &i : m)
    {
        sum += i.second;
        if (sum >= k)
        {
            ans = i.first;
            break;
        }
    }
    cout << ans << endl;

    // int n, k;
    // vector<ll> c(100000);
    // cin >> n >> k;
    // rep(i, n)
    // {
    //     int a, b;
    //     cin >> a >> b;
    //     c[a - 1] += b;
    // }
    // vector<ll> d(100000);
    // d[0] = c[0];
    // rep(i, 100000 - 1)
    // {
    //     d[i + 1] = d[i] + c[i + 1];
    // }
    // int ans = lower_bound(all(d), k) - d.begin();
    // cout << ans + 1 << endl;
    return 0;
}