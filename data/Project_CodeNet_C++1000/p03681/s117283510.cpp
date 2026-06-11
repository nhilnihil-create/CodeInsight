#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int const MOD = 1e9 + 7;
    int n, m;
    cin >> n >> m;

    ll ans = 1;
    if (abs(n - m) <= 1) {
        for (ll i = 1; i <= n; i++) ans = (ans * i) % MOD;
        for (ll i = 1; i <= m; i++) ans = (ans * i) % MOD;
        if (n == m) ans = (ans * 2) % MOD;
    } else
        ans = 0;

    cout << ans << endl;
    return 0;
}
