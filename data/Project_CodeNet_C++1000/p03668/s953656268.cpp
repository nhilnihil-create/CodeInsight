#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cassert>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

vector<vector<int>> G;

int dfs(int v = 0, int p = -1) {
    int res = 0;
    for (int u : G[v]) {
        if (u == p) continue;
        res ^= (dfs(u, v) + 1);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    G = vector<vector<int>>(n);
    REP(i, n - 1) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    cout << (dfs() ? "Alice\n" : "Bob\n");
    return 0;
}
