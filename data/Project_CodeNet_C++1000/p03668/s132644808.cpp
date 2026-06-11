#include <bits/stdc++.h>
using namespace std;

int n, u, v, grundy[200010];
vector<int> graph[200010];

void dfs(int u, int p) {
    for(int v : graph[u]) {
        if(v == p) continue;
        dfs(v, u);
        grundy[u] ^= (grundy[v] + 1);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 1);
    if(grundy[1]) printf("Alice");
    else printf("Bob");
}