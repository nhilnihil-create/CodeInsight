#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<ll, ll> P;
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    rep(i, n)
    {
        cin >> v[i];
    }
    ll ans = 1e18;
    for (ll i = 0; i < n; i++)
    {
        multiset<ll> b;
        ll s = m * i;
        for (ll j = 1; j <= i; j++)
        {
            b.insert(v[n - j]);
        }
        rep(j, n)
        {
            b.insert(v[j]);
            s += *b.begin();
            b.erase(b.find(v[(j - i + n) % n]));
        }
        ans = min(ans, s);
    }
    cout << ans << endl;
}