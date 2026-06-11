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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        ll sum = 0;
        set<int> ost;
        vector<ll> xx(n);

        for (int i = 0; i < n; ++i) {
            xx[i] = a[i] - a[(i - 1 + n) % n];
            sum += xx[i];
            ost.insert((xx[i] % n + n) % n);
        }
        ll max_el = *max_element(xx.begin(), xx.end());
        if (sum != 0 || ost.size() > 1) {
            cout << "NO";
            return;
        }
        vector<ll> cnt(n);
        for (int i = 0; i < n; ++i) {
            cnt[i] = (max_el - xx[i]) / n;
        }
        ll z = 0;
        ll ss = 0;
        for (int i = 0; i < n; ++i) {
            z += cnt[(n - i) % n] * (i + 1);
            ss += cnt[i];
        }

        for (int i = 0; i < n; ++i) {
            a[i] -= z;
            z += ss;
            z -= n * cnt[(i + 1) % n];
        }
        for (int i = 0; i + 1 < n; ++i) {
            if (a[i] != a[i + 1]) {
                cout << "NO";
                return;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] < 0 || a[i] % (n * (n + 1) / 2)) {
                cout << "NO";
                return;
            }
        }
        cout << "YES";
    };


    fast_io();
    cout.precision(9);
    cout << fixed;

    solve(1);


}
