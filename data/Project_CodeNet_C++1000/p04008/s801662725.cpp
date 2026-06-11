#include<bits/stdc++.h>
using namespace std;

int N, K, ans;
int par[100010], dp[100010];
vector<int> adj[100010];

void dfs(int u) {
    dp[u] = 0;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        dfs(v);
        dp[u] = max(dp[u], 1 + dp[v]);
    }
    if(par[u] && dp[u] == K - 1) {
        ans++;
        dp[u] = -1;
    }
}

int main() {
    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++) {
        scanf("%d", &par[i]);
        par[i]--;
    }

    ans = par[0] != 0;
    par[0] = 0;

    for(int i = 1; i < N; i++) {
        adj[ par[i] ].push_back(i);
    }

    dfs(0);
    cout << ans;
}
