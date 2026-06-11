#include <bits/stdc++.h>
using namespace std;

#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) rep2(i, 0, n)
#define all(a) a.begin(), a.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vvvi = vector<vector<vector<int>>>;
using mii = map<int, int>;
using msi = map<string, int>;
using pii = pair<int, int>;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << std::fixed << std::setprecision(10);

    int n, k;
    cin >> n >> k;
    vector<ll> a(n), s(n); // sはその前までで最も高いビルの高さ
    rep(i, n) cin >> a[i];
    ll h1 = a[0];
    rep2(i, 1, n)
    {
        if (h1 >= a[i - 1])
        {
            s[i] = h1;
        }
        else
        {
            s[i] = a[i - 1];
            h1 = s[i];
        }
    }
    ll ans = 2e18;
    rep(l, 1 << n)
    {
        if (k != __builtin_popcount(l))
            continue;
        if (!(l & 1))
            continue;
        ll h = a[0];
        ll ans1 = 0;
        rep(j, n)
        {
            if (j == 0)
                continue;
            if (l >> j & 1)
            {
                h = max(s[j], h);
                ans1 += max((ll)0, h - a[j] + 1);
                h = max(a[j], h + 1);
            }
        }
        ans = min(ans, ans1);
    }
    cout << ans << endl;

    return 0;
}