#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector <int> mn = a;
    ll ans = 2e18;
    for (int mx = 0; mx < n; ++mx) {
        for (int i = 0; i < n; ++i) mn[i] = min(mn[i], a[(i - mx + n) % n]);
        ll cur = (ll)mx * x;
        for (int i = 0; i < n; ++i) cur += mn[i];
        ans = min(ans, cur);
    }
    cout << ans << '\n';
}