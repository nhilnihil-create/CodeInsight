#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), prefsum(n + 1, 0), possum(n + 1, 0);
    rep(i, n) {
        cin >> a[i];
        prefsum[i + 1] = prefsum[i] + a[i];
        possum[i + 1] = possum[i] + max(0ll, a[i]);
    }

    ll ans = -1e18;
    for (int i = 0; i + k <= n; i++) {
        int l = i, r = i + k;
        // paint [l,r) either white or black
        ll tmp = max(0ll, prefsum[r] - prefsum[l]);
        // paint the rest as you wish
        tmp += possum[l];
        tmp += possum[n] - possum[r];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}