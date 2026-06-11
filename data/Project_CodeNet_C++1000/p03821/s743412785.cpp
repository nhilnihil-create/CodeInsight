#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i, n) cin >> a[i] >> b[i];
    ll ans = 0;
    for(ll i = n - 1; i >= 0; i--) {
        a[i] += ans;
        ll amari = a[i] % b[i];
        if(amari == 0) continue;
        ll tasu = b[i] - amari;
        ans += tasu;
    }
    cout << ans << endl;
    return 0;
}
