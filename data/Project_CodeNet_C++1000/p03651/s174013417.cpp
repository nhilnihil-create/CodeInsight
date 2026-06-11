#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll n, k; cin >> n >> k;

    ll mx = 0;

    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    if (mx < k) {
        puts("IMPOSSIBLE");
        return 0;
    }

    ll g = 0;
    for (ll i = 0; i < n; ++i) {
        g = __gcd(g, a[i]);
    }

    if (k % g == 0) {
        puts("POSSIBLE");
    } else {
        puts("IMPOSSIBLE");
    }
}