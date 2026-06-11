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

        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) { cin >> a[i]; }
        if (n == 2) {
            if (a[1] == a[2]) {
                cout << "YES";
            } else {

                cout << "NO";
            }
            return;
        }
        vector<vector<int>> g(n + 1);
        for (int i = 1; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        bool ok = true;
        vector<ll> res(n + 1);
        function<void(int, int)> dfs = [&](int v, int p) {
            ll mx = 0;
            ll sum = 0;
            int cnt = 0;
            for (int to:g[v]) {
                if (to == p) {
                    continue;
                }
                ++cnt;
                dfs(to, v);
                mx = max(mx, res[to]);
                sum += res[to];
            }
            if (!cnt) {
                res[v] = a[v];
                return;
            }
            ll mn_avail = (2 * mx > sum ? mx : sum - sum / 2);
            if (a[v] < mn_avail || a[v] > sum) {
                ok = false;
            }
            res[v] = sum - 2 * (sum - a[v]);
            if (res[v] < 0) {
                ok = false;
            }
        };
        int root = 1;
        for (int i = 1; i <= n; ++i) {
            if (g[i].size() == 2) {
                root = i;
            }
        }
        dfs(root, root);
        if (ok && !res[root]) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    };


    fast_io();
    cout.precision(9);
    cout << fixed;

    solve(1);


}
