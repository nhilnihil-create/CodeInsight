#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 7;

int n, k;
vector<int> e[maxn];

int dfs(int u, int pre, int d, int limit) {
    int rt = 0;
    if (d > limit) rt++;
    for (auto &v : e[u])
        if (v != pre) rt += dfs(v, u, d + 1, limit);
    return rt;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int ans = n;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dfs(i, -1, 0, k / 2));
    }
    for (int i = 1; i <= n; i++) {
        for (auto &v : e[i]) {
            if (v > i) continue;
            ans = min(ans, 
                dfs(i, v, 0, (k - 1) / 2) + dfs(v, i, 0, (k - 1) / 2));
        }
    }
    cout << ans << endl;
    return 0;
}