#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <complex>
#include <algorithm>
#include <numeric>
#include <utility>
#include <tuple>
#include <bitset>
#include <cstdint>
#include <cassert>
#include <random>
#include <iterator>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;

i64 n, m;
vector<vector<int>> g;

vector<int> col;
bool dfs(int u, int p, int c) {
    if (col[u] == -c) return false;
    if (col[u] == c) return true;
    col[u] = c;
    bool res = true;
    for (int v : g[u]) {
        if (v == p) continue;
        res = dfs(v, u, -c) & res;
    }
    return res;
}

int main() {
    cin >> n >> m;
    g.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    col.resize(n + 1);
    i64 cnt[2] = {};
    i64 iso = 0;
    for (int u = 1; u <= n; ++u) {
        if (g[u].size() == 0) {
            ++iso;
        } else if (col[u] == 0) {
            cnt[dfs(u, 0, 1)]++;
        }
    }
    cerr << "isolated: " << iso << endl;
    cerr << "cnt[0]: " << cnt[0] << endl;
    cerr << "cnt[1]: " << cnt[1] << endl;
    i64 ans = n * n - (n - iso) * (n - iso) + cnt[1] * cnt[1] + (cnt[0] + cnt[1]) * (cnt[0] + cnt[1]);
    cout << ans << endl;
    return 0;
}