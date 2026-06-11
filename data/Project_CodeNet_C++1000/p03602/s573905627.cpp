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

int a[301][301];

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
    mt19937 mt(234793824);
    auto solve = [&mt](int _) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j) {
                    continue;
                }
                for (int e = 1; e <= n; ++e) {
                    if (e == i || e == j) {
                        continue;
                    }
                    if (a[i][e] + a[e][j] < a[i][j]) {
                        cout << -1;
                        return;
                    }
                }
                if (a[i][j] != a[j][i]) {
                    cout << -1;
                    return;
                }
            }
        }
        ll cock = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (i == j) {
                    continue;
                }
                bool need = true;
                for (int e = 1; e <= n; ++e) {
                    if (e == i || e == j) {
                        continue;
                    }
                    if (a[i][j] >= a[i][e] + a[e][j]) {
                        need = false;
                    }
                }
                if (need) {
                    cock += a[i][j];
                }
            }
        }
        cout << cock;
    };


    fast_io();

    cout.precision(9);
    cout <<
         fixed;
    for (int i = 1; i <= 1; ++i)
        solve(1);


}
