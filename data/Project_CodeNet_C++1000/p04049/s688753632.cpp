#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> adj[2005];
ll d,ans;
void dfs(ll u,ll pr,ll dist){
    if(dist>d/2)ans++;
    for(auto &v:adj[u])if(v!=pr)dfs(v,u,dist+1);
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n;cin>>n>>d;
    for(ll i=0,u,v;i<n-1;i++)cin>>u>>v,adj[u].push_back(v),adj[v].push_back(u);
    ll fin = n;
    if(d%2==0){
        for(ll i=1;i<=n;i++){
            ans=0;
            dfs(i,i,0);
            fin=min(fin,ans);
           // cout<<i<<"-->"<<ans<<endl;
        }
    }
    else{
        for(ll i=1;i<=n;i++){
            for(auto &j:adj[i]){
                ans=0;
                dfs(i,j,0);
                dfs(j,i,0);
                fin=min(fin,ans);
               // cout<<i<<","<<j<<"-->"<<ans<<endl;
            }
        }
    }
    cout<<fin;
}


