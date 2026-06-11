#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    ll a[n], b[n];
    rep(i, n) { cin >> a[i] >> b[i]; }

    ll ans = 0;
    ll buf = 0;
    repb(i, n) {
        ll m = (a[i] + buf) % b[i];
        if (m != 0) {
            ans += b[i] - m;
            buf += b[i] - m;
        }
    }
    cout << ans << endl;
    return 0;
}

