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
    int n;
    cin >> n;
    vector<pair<int, int>> values;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        values.emplace_back(a[i], i & 1);
    }
    sort(values.begin(), values.end());
    int cnt = 0;
    for (int i = 0; i < values.size(); ++i) {
        int cur = i + 1;
        if ((values[i].second & 1) != (cur & 1)) {
            ++cnt;
        }
    }
    cout << cnt / 2;

    auto end = chrono::steady_clock::now();
    debug("time", chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0);

}

