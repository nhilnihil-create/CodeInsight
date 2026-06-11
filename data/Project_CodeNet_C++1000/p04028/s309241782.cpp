#include <bits/stdc++.h>


using namespace std;


#ifdef zxc

#include "debug.h"

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ll = int64_t;
using ld = long double;
const ld EPS = 1e-8;
const ll MOD = 1e9 + 7;
const ld PI = 3.141592653589793;
const int maxn = 10001;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

ll mul(ll a, ll b) {
    return a * b % MOD;
}

ll dp[5001][5001];

ll pw[5001];

signed main() {
#ifdef zxc
    mt19937 mt(228);
    freopen("../kolya_input.txt", "r", stdin);
//    freopen("../kolya_output.txt", "w", stdout);
#else
    mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
//            freopen("", "r", stdin);
//        freopen("hack.out", "w", stdout);
#endif
    fast_io();
    cout.precision(10);
    cout << fixed;
    auto start = chrono::steady_clock::now();
    int n;
    cin >> n;
    string s;
    cin >> s;
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int bal = 0; bal < n; ++bal) {
            dp[i + 1][bal + 1] += dp[i][bal];
            if (dp[i + 1][bal + 1] >= MOD) {
                dp[i + 1][bal + 1] -= MOD;
            }
            if (bal) {
                dp[i + 1][bal - 1] += dp[i][bal];
                if (dp[i + 1][bal - 1] >= MOD) {
                    dp[i + 1][bal - 1] -= MOD;
                }
            }
        }
    }
    ll ans = 0;
    ll bal = s.size();
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = pw[i - 1] * 2 % MOD;
    }
    for (int del = 0; del < n; ++del) {
        if (n - del - bal >= 0) {
            for (int x = 0; x <= del; ++x) {
                ans += dp[n - del - 1][bal - 1] * pw[(n - del - bal) / 2] % MOD * dp[del][x] % MOD * pw[(del - x) / 2] %
                       MOD;
                if (ans >= MOD) {
                    ans -= MOD;
                }
            }

        }
    }
    cout << ans;

    auto end = chrono::steady_clock::now();
    debug("time", chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0);

}

