#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;

#define int long long

void solve() {
    int n, m;
    int ans1 = 1, ans2=1;
    cin >> n >> m;
    int cn, cm;
    if (abs(n - m) > 1) {
        cout << 0;
        return;
    }
    int t;
    if (n < m) {
        t = m;
        m = n;
        n = t;
    }
    cn = n; cm = m;
    for (int i = 0; i < n; ++i) {
        ans1 = (ans1 *= cn--) % mod;
    }
    for (int i=0; i < m; ++i) {
        ans2 = (ans2 *= cm--) % mod;
    }
    int ans;
    ans = (ans1 * ans2) % mod;
    if (n == m) {
        ans = (ans *= 2) % mod;
    }
    cout << ans;
}

 signed main() {
	solve();
    return 0;
}
