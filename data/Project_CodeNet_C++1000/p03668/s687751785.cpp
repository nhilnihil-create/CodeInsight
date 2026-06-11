#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, f[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    function<void(int, int)> dfs = [&](int v, int fa) {
        for (int u : G[v]) if (u ^ fa) {
            dfs(u, v), f[v] ^= f[u] + 1;
        }
    };
    dfs(1, 0), printf("%s\n", f[1] ? "Alice" : "Bob");
    return 0;
}