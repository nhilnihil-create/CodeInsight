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
const ld EPS = 1e-10;
const ll MOD = 1e9 + 7;
const ld PI = 3.141592653589793;
const int maxn = 200001;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int a[maxn];
ll dp[maxn][3];

signed main() {
#ifdef zxc
    mt19937 mt(228);
    freopen("../kolya_input.txt", "r", stdin);
//    freopen("../kolya_output.txt", "w", stdout);
#else
    //    mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    //            freopen("", "r", stdin);
    //        freopen("hack.out", "w", stdout);
#endif
    fast_io();
    cout.precision(1);
    cout << fixed;
    auto start = chrono::steady_clock::now();
    ll ans = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] & 1) {
            ans += a[i] / 2;
            a[i] = 1;
        } else if (a[i]) {
            ans += (a[i] - 1) / 2;
            a[i] = 2;
        }

    }


    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i][1] = dp[i][2] = -1e15;
    }
    dp[1][a[1]] = ans;
    if (a[1] == 2) {
        dp[1][0] = ans + 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int z = 0; z <= a[i]; ++z) { // to dec
            for (int e = z; e <= 2; ++e) {
                dp[i][a[i] - z] = max(dp[i][a[i] - z], dp[i - 1][e] + z);
            }
            if (z == 2) {
                for (int e = 0; e <= 2; ++e) {
                    dp[i][0] = max(dp[i][0], dp[i - 1][e] + 1);
                }
            }
        }
//        debug(i, dp[i][0]);
//        debug(i, dp[i][1]);
//        debug(i, dp[i][2]);
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]});
    auto end = chrono::steady_clock::now();
    debug("time", chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0);

}

