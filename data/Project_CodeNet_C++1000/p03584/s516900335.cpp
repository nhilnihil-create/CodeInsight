#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define forn(i, n) for (ll i = 0; i < (n); i++)
#define fori(i, b, e) for (ll i = (b); i < (e); i++)
#define forr(i, b, e) for (ll i = (b); i >= (e); i--)
#define allele(v) v.begin(), v.end()
#define fi first
#define se second
#define Mat vector<vector<ll>>
#define Arr vector<ll>

vector<pair<ll, ll>> v;
ll func(ll k)
{
    ll n = v.size();
    ll ans = 0;
    forn(i, n)
    {
        bool flag = true;
        ll x = v[i].fi;
        forn(j, 31)
        {
#define getbit(x, i) (((x) >> (i)) & 1)
            if (!getbit(k, j) && getbit(x, j))
                flag = false;
        }
        if (flag)
            ans += v[i].se;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    v = vector<pair<ll, ll>>(n);
    forn(i, n) cin >> v[i].fi >> v[i].se;

    ll ans = func(k);
    forn(i, 31)
    {
        ll x = k;
        if (getbit(x, i))
        {
            x &= ((1LL << 32) - 1 - (1LL << i));
            x |= ((1LL << i) - 1);
            ans = max(ans, func(x));
        }
    }
    cout << ans;
    return 0;
}