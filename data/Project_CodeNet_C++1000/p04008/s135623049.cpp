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
const int maxn = 200001;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}


ll a[maxn];
ll dp[maxn];
int k;
vector<int> g[maxn];
int nosex[maxn];
int ans = 0;
bool change[maxn];

void dfs(int v) {
    nosex[v] = 0;
    for (int to:g[v]) {
        dfs(to);
        if (!change[to]) {
            nosex[v] = max(nosex[v], nosex[to]);
        }
    }
    if (nosex[v] == k - 1) {
        if (a[v] != 1)
            change[v] = 1;
    } else {
        nosex[v]++;
    }
    if (v != 1)
        ans += change[v];
}

signed main() {
#ifdef zxc
    mt19937 mt(228);
    freopen("../kolya_input.txt", "r", stdin);
//    freopen("../kolya_input.txt", "w", stdout);
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

    cin >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    if (a[1] != 1) {
        a[1] = 1;
        ++ans;
    }
    for (int i = 2; i <= n; ++i) {
        g[a[i]].push_back(i);
    }
    dfs(1);
    cout << ans;
    auto end = chrono::steady_clock::now();
    debug("time", chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0);

}

