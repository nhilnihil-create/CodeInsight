#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll n, a, b; cin >> n >> a >> b;

    vector<ll> x(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i];
    }

    ll ans = 0;
    for (ll i = 1; i < n; ++i) {
        ll t = x[i] - x[i-1];

        if (t * a > b) {
            ans += b;
        } else {
            ans += t * a;
        }
    }

    cout << ans << endl;
}