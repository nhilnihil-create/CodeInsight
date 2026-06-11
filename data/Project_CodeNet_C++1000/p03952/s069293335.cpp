#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;


#ifdef zxc

#include <sys/resource.h>
#include "debug.h"

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ll = int64_t;
using ld = double;
const ld EPS = 1e-9;
//const ll MOD = 924844033;
const ld PI = 3.141592653589793;
const int maxn = 300001;

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
    freopen("../kolya_input.txt", "r", stdin);
//    freopen("../kolya_output.txt", "w", stdout);
#else
    //    mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    //            freopen("", "r", stdin);
    //        freopen("hack.out", "w", stdout);
#endif
    fast_io();
    cout.precision(9);
    cout << fixed;
    auto start = chrono::steady_clock::now();
    int n;
    cin >> n;
    int x;
    cin >> x;
    if (x == 1 || x == 2 * n - 1) {
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
    vector<int> ans(2 * n);
    set<int> used;
    ans[n] = x;
    ans[n + 1] = x - 1;
    ans[n - 1] = x + 1;
    used.insert(x);
    used.insert(x + 1);
    used.insert(x - 1);
    if (n > 2) {
        if (x + 2 < 2 * n) {
            ans[n + 2] = x + 2;
            used.insert(x + 2);
        } else {
            ans[n - 2] = x - 2;
            used.insert(x - 2);
        }

    }
    set<int> unused;

    for (int i = 1; i <= 2 * n - 1; ++i) {
        if (!used.count(i)) {
            unused.insert(i);
        }
    }
    for (int i = 1; i < ans.size(); ++i) {
        if (!ans[i]) {
            int el = *unused.begin();
            unused.erase(el);
            ans[i] = el;
        }
    }
    for (int i = 1; i < ans.size(); ++i) {
        cout << ans[i] << "\n";
    }
    auto end = chrono::steady_clock::now();

    debug("time", chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0);

}

