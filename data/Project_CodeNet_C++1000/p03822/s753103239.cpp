#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, f[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 2, a; i <= n; i++) {
        scanf("%d", &a), G[a].push_back(i);
    }
    function<void(int)> dfs = [&](int v) {
        vector<int> V;
        for (int u : G[v]) dfs(u), V.push_back(f[u]);
        sort(V.begin(), V.end(), greater<int>());
        for (int i = 0; i < V.size(); i++) {
            f[v] = max(f[v], V[i] + i + 1);
        }
    };
    dfs(1), printf("%d\n", f[1]);
    return 0;
}