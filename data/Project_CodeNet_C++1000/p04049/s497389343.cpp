#include <bits/stdc++.h>
#define INF 1234567890
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pii;

int N, K;
int ans=INF;
vector<int> G[2020], V[2020];
int dis[2020][2020];
bool chk[2020][2020];

void dfs(int r, int u, int p, int d){
    dis[r][u] = d;
    if (d <= K) V[r].push_back(u);
    for (int v : G[u]){
        if (v == p) continue;
        dfs(r, v, u, d+1);
    }
}

int main(){
    int u, v;
    scanf("%d %d", &N, &K);
    for (int i=1; i<N; i++){
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i=1; i<=N; i++) dfs(i, i, 0, 0);
    for (int i=1; i<=N; i++){
        for (int j=1; j<=N; j++){
            if (dis[i][j] == K && !chk[i][j]){
                int cnt = 0;
                for (int k : V[i]){
                    if (dis[j][k]<=K){
                        cnt++;
                        chk[i][k] = chk[j][k] = true;
                        chk[k][i] = chk[k][j] = true;
                    }
                }
                ans = min(ans, N-cnt);
            }
        }
    }
    if (ans == INF) printf("0");
    else printf("%d", ans);
    return 0;
}
