#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll n; cin >> n;
    vector<ll> a(3 * n);
    for (ll i = 0; i < 3 * n; ++i) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    ll ans = 0;
    for (ll i = 0; i < 2 * n; i += 2) {
        ans += min(a[i], a[i + 1]);
    }

    cout << ans << endl;
}