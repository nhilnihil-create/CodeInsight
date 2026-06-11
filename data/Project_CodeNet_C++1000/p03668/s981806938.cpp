#include<bits/stdc++.h>
using namespace std;

int N;
vector<vector<int> > adj;
vector<int> dp;

void dfs(int u, int p) {
    dp[u] = 0;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == p) continue;
        dfs(v, u);
        dp[u] ^= dp[v];
    }
    dp[u]++;
}

int main() {
    scanf("%d", &N);

    adj.resize(N);
    for(int i = 0; i < N - 1; i++) {
        int u, v; scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dp.resize(N);
    dfs(0, -1);

    int Xor = 0;
    for(int i = 0; i < adj[0].size(); i++) {
        Xor ^= dp[ adj[0][i] ];
    }
    if(Xor) printf("Alice");
    else printf("Bob");
}
