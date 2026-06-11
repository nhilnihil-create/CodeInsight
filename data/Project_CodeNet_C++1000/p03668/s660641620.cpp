#include<bits/stdc++.h>
#define ll long long int
#define INF 0x3f3f3f3f
#define pb push_back
#define se second
#define fi first
using namespace std;
const int N=1e5+5;
int vis[N],grundy[N];
vector<int> g[N];

void dfs(int u){
    vis[u]=1;
    for(int v:g[u]){
        if(vis[v]) continue;
        dfs(v);
        grundy[u]^=(grundy[v]+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n; cin>>n;
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        g[u].pb(v); g[v].pb(u);
    }
    dfs(1);
    cout<<(grundy[1]?"Alice":"Bob");
    return 0;
}