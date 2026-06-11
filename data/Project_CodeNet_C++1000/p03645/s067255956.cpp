#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)
const ll LINF = 1001002003004005006ll;

bool dfs(int now, int pre, int n, vector<vector<int>> &g, int cnt) {
    if (cnt == 2) {
        return now == n - 1;
    }
    bool ok = false;
    for (auto a: g[now]) {
        if (a == pre) continue;
        ok |= dfs(a, now, n, g, cnt+1);
    }
    return ok;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (dfs(0, -1, n, g, 0)) {
        cout << "POSSIBLE" << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
