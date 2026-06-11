#include <bits/stdc++.h>

using namespace std;


#ifdef zxc

#include <sys/resource.h>
#include "debug.h"

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ll = int64_t;
using ld = long double;
const ld EPS = 1e-9;
//const ll MOD = 924844033;
const ld PI = 3.141592653589793;
const int maxn = 300001;
const ll MOD = 998244353;

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


    function<void(int)> solve = [](int t) {
        int n;
        cin >> n;
        vector<int> x(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }
        vector<int> diff(n);
        for (int i = 1; i < n; ++i) {
            diff[i] = x[i] - x[i - 1];
        }
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        ll m, k;
        cin >> m >> k;
        for (int i = 0; i < m; ++i) {
            int a;
            cin >> a;
            --a;
            swap(p[a], p[a + 1]);
        }
        vector<int> used(n);
        vector<int> cmp;
        vector<int> res(n);
        function<void(int)> dfs = [&](int v) {
            used[v] = 1;
            cmp.push_back(v);
            if (!used[p[v]]) {
                dfs(p[v]);
            }
        };
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                cmp.clear();
                dfs(i);
                for (int e = 0; e < cmp.size(); ++e) {
                    res[cmp[e]] = cmp[(k + e) % cmp.size()];
                }
            }
        }
        cout << x[0] << "\n";
        ll last = x[0];
        for (int i = 1; i < n; ++i) {
            last = last + diff[res[i]];
            cout << last << "\n";
        }
    };


    fast_io();
    cout.precision(9);
    cout << fixed;
    auto start = chrono::steady_clock::now();
    for (int i = 1; i <= 1; ++i)solve(i);
    auto end = chrono::steady_clock::now();

    debug("time", chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0);

}
