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
    ll n, c, k;
    cin >> n >> c >> k;
    ll t[n];
    rep(i, n) { cin >> t[i]; }
    sort(t, t + n);
    ll index = 0;
    ll ans = 0;
    ll bus = 1;
    repd(i, 1, n) {
        if (bus == c) {
            ans++;
            index = i;
            bus = 1;
            continue;
        }
        if (t[index] + k < t[i]) {
            ans++;
            index = i;
            bus = 1;
            continue;
        }
        bus++;
    }
    if (bus) {
        ans++;
    }

    cout << ans << endl;

    return 0;
}

