#include <bits/stdc++.h>

const int N = 100000 + 10;

int n, k, ans;
std::vector <int> e[N];
int v[N];

int dfs (int u, int dep = 0) {
    int ret = dep;
    for (auto i : e[u]) ret = std::max(ret, dfs(i, dep + 1));
    if (v[u] ^ 1 && ret - dep == k - 1) {
        ans++;
        return 0;
    }
    return ret;
}

int main () {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", v + i);
    if (v[1] ^ 1) v[1] = 1, ans++;
    for (int i = 2; i <= n; i++) e[v[i]].push_back(i);
    dfs(1); printf("%d", ans);
    return 0;
}

