#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n,dist[2][100001];
vector<int> adj[100001];

void dfs(int cur,int p,int c,int d) {
    dist[c][cur]=d;
    for(auto &it:adj[cur]) if(it!=p) dfs(it,cur,c,d+1);
}
int main() {
    scanf("%d",&n);
    for(int i=1,u,v;i<n;i++) {
        scanf("%d%d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0,0,0);
    dfs(n,0,1,0);

    int cnt[2];
    for(int i=1;i<=n;i++) {
        if(dist[0][i] <= dist[1][i]) cnt[0]++;
        else cnt[1]++;
    }
    if(cnt[0]<=cnt[1]) puts("Snuke");
    else puts("Fennec");
    
    return 0;
}
