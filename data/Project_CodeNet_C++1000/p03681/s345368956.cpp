#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1000000000 + 7;

bool debug = 0;

ll fracmod(ll n) {
    ll ret = 1;
    for (int i = 1; i <= n; i++) {
        ret *= i;
        ret %= MOD;
    }
    return ret;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    ll ans;
    ans = fracmod(n) * fracmod(m) % MOD;
    if (n == m) ans *= 2;
    if (abs(n - m) > 1) ans = 0;
    ans %= MOD;
    cout << ans << endl;
}

int main() {
    if (debug) {
        while (true) {
            cout << "********" << endl;
            solve();
        }
    } else {
        solve();
    }
    return 0;
}