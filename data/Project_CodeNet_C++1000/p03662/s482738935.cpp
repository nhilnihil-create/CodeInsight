#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e5+5;
ll n,a,b,dist[2][N];
vector<ll> adj[N];
void dfs(ll u,ll pr,ll d,ll idx){
    dist[idx][u]=d;
    for(auto &v:adj[u])if(v!=pr)dfs(v,u,d+1,idx);
}
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    cin>>n;
    for(ll i=0,u,v;i<n-1;i++)cin>>u>>v,adj[u].push_back(v),adj[v].push_back(u);
    dfs(1,1,0,0);dfs(n,n,0,1);
    for(ll i=1;i<=n;i++)if(dist[0][i]<=dist[1][i])a++;
    cout<<(a>n-a?"Fennec":"Snuke");
}