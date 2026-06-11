#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll>pi;
#define pb push_back
//ll adj[1001][1005];
vector<pi>adj[1005];
ll dist[1005];
#define mn -10000000000000
int main()
{
    ll n,m;cin>>n>>m;
    for(ll i=0;i<m;i++)
    {
        ll u,v,w;cin>>u>>v>>w;
//        adj[u][v]=w;
        adj[u].pb({w,v});
    }
//    bool cycle=false;
    bool cycle[1005];
    for(ll i=0;i<=n;i++)dist[i]=mn;
    dist[1]=0;
    for(ll i=0;i<n-1;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            for(ll k=0;k<adj[j].size();k++)
            {
                ll chi=adj[j][k].second;
                ll cst=adj[j][k].first;
                if(dist[j]+cst>dist[chi])
                {
                    dist[chi]=dist[j]+cst;
                }
            }
        }
    }
    memset(cycle,0,sizeof cycle);
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=0;k<adj[j].size();k++)
            {
                ll chi=adj[j][k].second;
                ll cst=adj[j][k].first;
                if(dist[j]+cst>dist[chi])
                {
                    dist[chi]=dist[j]+cst;
                    cycle[chi]=true;
                }
            }
        }
    }
    if(cycle[n]==true)cout<<"inf"<<endl;
    else cout<<dist[n]<<endl;
}
