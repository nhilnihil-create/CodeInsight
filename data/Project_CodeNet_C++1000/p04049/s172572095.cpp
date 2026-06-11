#include <bits/stdc++.h>
using namespace std;
vector<int> g[2002];
bool vis[2002];
int D[2002];
void dfs(int u, int d){
    vis[u] = 1;
    D[u] = d;
    for(int i=0;i<g[u].size();i++){
        int v = g[u][i];
        if(vis[v]) continue;
        dfs(v, d+1);
    }
}
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=1;i<=n-1;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    if(k%2 == 0){
        int ans = 1e9;
        for(int i=1;i<=n;i++){
            memset(vis, 0, sizeof(vis));
            dfs(i, 0);
            int res = 0;
            for(int j=1;j<=n;j++){
                if(D[j] > k/2) res++;
            }
            ans = min(ans, res);
        }
        printf("%d\n", ans);
    }
    else{
        int ans = 1e9;
        for(int i=1;i<=n;i++){
            for(int j=0;j<g[i].size();j++){
                memset(vis, 0, sizeof(vis));
                int u = i, v = g[i][j];
                vis[u] = 1, vis[v] = 1;
                dfs(u, 0);
                dfs(v, 0);
                int res = 0;
                for(int j=1;j<=n;j++){
                    if(D[j] > k/2) res++;
                }
                ans = min(ans, res);
            }
        }
        printf("%d\n", ans);
    }
}