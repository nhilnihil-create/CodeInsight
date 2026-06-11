#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3e5+5,mod=1e9+7;
vector<ll> adj[N];
bool vis[N];
deque<ll> dq;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;cin>>n>>m;
    for(ll i=1;i<=m;i++){
        ll u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dq.push_back(1);
    vis[1]=1;
    while(1){
        ll node=-1;
        for(auto &v:adj[dq.front()])if(!vis[v])node=v;
        if(node!=-1){
            dq.push_front(node);
            vis[node]=1;
            continue;
        }
        for(auto &v:adj[dq.back()])if(!vis[v])node=v;
        if(node!=-1){
            dq.push_back(node);
            vis[node]=1;
            continue;
        }
        break;
    }
    cout<<dq.size()<<"\n";
    for(auto &ele:dq)cout<<ele<<" ";
}