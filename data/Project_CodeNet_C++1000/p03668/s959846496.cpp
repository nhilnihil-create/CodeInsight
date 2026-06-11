#include<bits/stdc++.h>
using namespace std;

const int MN = 100010;

int N;
vector<int> adj[MN];
int dp[MN];

void dfs(int u, int p) {
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == p) continue;
        dfs(v, u);
        dp[u] ^= (dp[v] + 1);
    }
}

int main() {
    scanf("%d", &N);

    for(int i = 0; i < N - 1; i++) {
        int u, v; scanf("%d %d", &u, &v);
        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    if(dp[0]) printf("Alice");
    else printf("Bob");
}
