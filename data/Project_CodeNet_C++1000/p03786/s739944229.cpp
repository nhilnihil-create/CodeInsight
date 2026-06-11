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
    vector<ll> a(n);
    rep(i, n) { cin >> a[i]; }
    sort(a.begin(), a.end());
    vector<ll> sum(n);
    sum[0] = a[0];

    repd(i, 1, n) { sum[i] = sum[i - 1] + a[i]; }

    ll ans = 1;
    rep(i, n - 1) {
        if (sum[i] * 2 < a[i + 1]) {
            ans = 1;
        } else {
            ans++;
        }
        // cout << i << ":" << ans << endl;
    }
    cout << ans << endl;
    return 0;
}

