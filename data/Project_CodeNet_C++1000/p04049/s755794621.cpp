#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;

int n, k;
vector<vector<int>> g(4000, vector<int>());

int cnt(int cur, int prev)
{
    // cout << cur << ", " << prev << endl;

    int ret = 1;
    for (auto &n: g[cur]) {
        if (n == prev) continue;
        ret += cnt(n, cur);
    }
    return ret;
}

int solve(int cur, int prev, int dep)
{
    // cout << cur << ", " << prev << ", " << dep << endl;

    if (dep <= 0) {
        return cnt(cur, prev);
    }

    int ans = 0;

    for (int i = 0; i < (int)g[cur].size(); i++) {
        if (g[cur][i] == prev) continue;
        ans += solve(g[cur][i], cur, dep - 1);
    }

    return ans;
}

int main()
{
    cin >> n >> k;
    g.resize(n);

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ans = n + 1;

    for (int center = 0; center < n; center++) {
        for (auto lng: g[center]) {
            int tmp = 0;
            for (auto root: g[center]) {
                tmp += solve(root, center, k / 2 + ((k % 2 == 1 && lng == root) ? 1 : 0));
            }
            // cout << center + 1 << " -> " << lng + 1 << ": " << tmp << endl;
            ans = min(ans, tmp);
        }
    }

    cout << ans << endl;

    return 0;
}