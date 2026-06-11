#include <bits/stdc++.h>
#define N 100005

using namespace std;

int n;
vector<int> g[N];

int dfs(int u, int fa) {
    int sg = 0;
    for(auto v : g[u]) {
        if(v == fa) continue;
        sg ^= dfs(v, u) + 1;
    }
    return sg;
}

int main() {
    scanf("%d", &n);
    for(int i = 1, u, v; i < n; ++i) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    puts(dfs(1, 0) ? "Alice" : "Bob");
    return 0;
}