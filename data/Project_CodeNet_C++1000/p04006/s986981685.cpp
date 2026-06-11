#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll ans = 1e18;
    vector<ll> mincost(n, 1e18);
    rep(i, n) {
        ll tmp = 0;
        rep(j, n) {
            mincost[j] = min(mincost[j], a[(i + j) % n]);
            tmp += mincost[j];
        }
        ans = min(ans, tmp + x * i);
    }
    cout << ans << endl;
}