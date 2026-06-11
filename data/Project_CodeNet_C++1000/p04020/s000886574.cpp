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
    ll a[n];
    rep(i, n) { cin >> a[i]; }

    ll ans = 0;
    rep(i, n) {
        ans += a[i] / 2;
        a[i] %= 2;
        if (i != n - 1) {
            if (a[i] && a[i + 1]) {
                a[i]--;
                a[i + 1]--;
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}

