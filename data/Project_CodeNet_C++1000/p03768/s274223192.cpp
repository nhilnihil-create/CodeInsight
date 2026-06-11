#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e5+5;
vector<ll> adj[N];
ll n,m,q,ans[N],vis[N][15],v[N],d[N],c[N];
void dfs(ll u,ll d,ll c){
    if(vis[u][d])return;
    vis[u][d]=1;
    if(d==0){
        ans[u]=c;
        return;
    }
    dfs(u,d-1,c);
    for(auto &v:adj[u])
        dfs(v,d-1,c);
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(ll i=0,u,v;i<m;i++)cin>>u>>v,adj[u].push_back(v),adj[v].push_back(u);
    cin>>q;
    for(ll i=0;i<q;i++)cin>>v[i]>>d[i]>>c[i];
    for(ll i=q-1;i>=0;i--)dfs(v[i],d[i],c[i]);
    for(ll i=1;i<=n;i++)cout<<ans[i]<<"\n";
}
