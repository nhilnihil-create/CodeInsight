#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;
const int MOD = INF + 7;

int main() {
    ll n, m;
    cin >> n >> m;

    ll ans = 1;
    if (abs(n - m) <= 1) {
        rep(i, n) ans = ans * (i + 1) % MOD;
        rep(i, m) ans = ans * (i + 1) % MOD;

        if (n == m)
            ans = ans * 2 % MOD;
    } else
        ans = 0;

    cout << ans << endl;

    return 0;
}