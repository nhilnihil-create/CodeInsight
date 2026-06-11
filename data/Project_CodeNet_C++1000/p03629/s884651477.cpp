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


        string s;
        cin >> s;
        int n = s.size();
        vector<pair<int, char>> par(n + 1);
        vector<int> used(n + 1);
        set<int> pos[26];
        {
            int x = 0;
            for (auto c:s) {
                pos[c - 'a'].insert(x);
                ++x;
            }
        }
        queue<int> q;
        vector<int> dp(n + 1);
        q.emplace(-1);
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            for (char c = 'a'; c <= 'z'; ++c) {
                auto it = pos[c - 'a'].upper_bound(v);
                int nv = n;
                if (it != pos[c - 'a'].end()) {
                    nv = *it;
                }
                if (!used[nv]) {
                    par[nv] = {v, c};
                    used[nv] = 1;
                    q.emplace(nv);
                }
            }
        }
        string ans;
        int x = n;
        while (x != -1) {
            auto it = par[x];
            ans.push_back(it.second);
            x = it.first;
        }
        reverse(ans.begin(), ans.end());
        cout << ans;
    };


    fast_io();
    cout.precision(9);
    cout << fixed;

    solve(1);


}
