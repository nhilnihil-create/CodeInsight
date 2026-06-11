#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (ll i = (ll)(start); i < (ll)(n); ++i)
static const ll INFTY = 1L << 62L;
ll solver()
{
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    ll v[n + 1] = {};
    ll a, b;
    rep(i, 0, m)
    {
        cin >> a >> b;
        ++v[a], ++v[b];
    }
    ll ans = true;
    rep(i, 1, n + 1)
    {
        if (v[i] % 2)
        {
            ans = false;
            break;
        }
    }
    if (ans)
        cout << "YES\n";
    else
    {
        cout << "NO\n";
    }
}