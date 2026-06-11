#include <bits/stdc++.h>

using namespace std;


#ifdef zxc

#include <sys/resource.h>
#include "debug.h"
#include "profile.h"

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define profile(X) LOG_DURATION(X)
#else
#define debug(...) 42
#define profile(...) 42
#endif

using ll = int64_t;
using ld = double;
const ld EPS = 1e-9;
//const ll MOD = 924844033;
const ld PI = 3.141592653589793;
const int maxn = 600001;
const int MOD = 1e9 + 7;
using cd = complex<double>;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

ll dp[101][4][4];

signed main() {
#ifdef zxc
    struct rlimit rl;
    const rlim_t kStackSize = 512L * 1024L * 1024L;
    assert(!getrlimit(RLIMIT_STACK, &rl));
    rl.rlim_cur = kStackSize;
    assert(!setrlimit(RLIMIT_STACK, &rl));
    freopen("../input.txt", "r", stdin);
//    freopen("../kolya_output.txt", "w", stdout);
#else
    //    mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    //            freopen("", "r", stdin);
    //        freopen("hack.out", "w", stdout);
#endif
    profile("all");

    auto solve = [](int _) {
        int n;
        cin >> n;
        vector<int> p(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }
        int ans = 0;
        for (int i = 1; i <= n;) {
            if (p[i] == i) {
                if (i == n) {
                    swap(p[i], p[i - 1]);
                    ++ans;
                    ++i;
                } else {
                    swap(p[i], p[i + 1]);
                    ++ans;
                    i += 2;
                }
            }
            else{
                ++i;
            }
        }
        cout<<ans;
    };


    fast_io();
    cout.precision(9);
    cout << fixed;

    solve(1);


}
