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
const int MOD = 1e9 + 7;
const ld PI = 3.141592653589793;
const int maxn = 600001;
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
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        vector<pair<int, int>> seg;
        ll sum = 0;
        for (int i = 1; i < n; ++i) {
            sum += (a[i + 1] - a[i] + m) % m;
            if (a[i + 1] < a[i]) {
                seg.push_back({a[i] - m, a[i + 1]});
                seg.push_back({a[i], a[i + 1] + m});
            } else {
                seg.push_back({a[i], a[i + 1]});
                seg.push_back({a[i] + m, a[i + 1] + m});
            }
        }
        map<int, vector<pair<int, int>>> events;
        for (int i = 0; i < seg.size(); ++i) {
            int x, y;
            tie(x, y) = seg[i];
            events[x + 1].emplace_back(1, i);
            events[y + 1].emplace_back(-1, i);
        }
        ll best = 1e18;
        ll cur = 0;
        for (auto p:seg) {
            cur += p.second - p.first;
        }
        int open_cnt = 0;
        for (int x = -3 * m; x <= 3 * m; ++x) {
            for (auto ev:events[x]) {
                if (ev.first == -1) {
                    --open_cnt;
                    cur += seg[ev.second].second - seg[ev.second].first - 1;
                }
            }
            cur -= open_cnt;
            best = min(best, cur - sum);
            for (auto ev:events[x]) {
                if (ev.first == 1) {
                    ++open_cnt;
                }
            }
        }
        cout<<best;
    };


    fast_io();

    cout.precision(9);
    cout <<
         fixed;
    for (int i = 1; i <= 1; ++i)
        solve(1);


}
