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

signed main()
{
    int n, c, k;
    cin >> n >> c >> k;
    vi t(n);
    rep(i, n)
    {
        cin >> t[i];
    }
    sort(all(t));
    int ans = 0;
    rep(i, n)
    {
        int cnt = 0;
        for (int j = i; j <= i + c - 1 && j < n; j++)
        {
            if (t[j] <= t[i] + k)
            {
                cnt++;
            }
        }
        //        cerr << cnt << endl;
        ans++;
        i += cnt - 1;
    }
    cout << ans << endl;
    return 0;
}