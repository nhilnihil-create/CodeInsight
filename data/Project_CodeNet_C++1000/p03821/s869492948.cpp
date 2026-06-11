#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll n; cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    ll ans = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 0 && ans == 0) continue;
        if (a[i] == 0 && ans > 0 && b[i] == 1) continue;
        if (a[i] > 0 && b[i] == 1) continue;
        if ((a[i] + ans) % b[i] == 0) continue;

        ll t = (a[i] + ans) / b[i];
        ans += (t + 1) * b[i] - (a[i] + ans);
    }

    cout << ans << endl;
}