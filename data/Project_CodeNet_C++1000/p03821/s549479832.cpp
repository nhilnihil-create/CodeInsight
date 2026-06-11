#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    ll ans = 0;
    for (ll i = n - 1; i >= 0; i--) {
        if ((a[i] + ans) % b[i] == 0) continue;
        ll r = (ans + a[i]) / b[i];
        ll toadd = ((r + 1) * b[i]) - (ans + a[i]);
        ans += toadd;
    }
    cout << ans << endl;
}