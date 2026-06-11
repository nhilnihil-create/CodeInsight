#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define pll pair<ll,ll>
#define ff first
#define ss second
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;
vector<pll>vec[100006];
ll dist[100006];
ll INF=2000000000000000000;
ll n,a,b,c,q,k;
void dijkstra(ll node)
{
    fill(dist,dist+n+1,INF);
    priority_queue<pll,vector<pll>,greater<pll>>que;
    que.push({node,0});
    while(que.size()){
        pll p=que.top();
        que.pop();
        ll u=p.ff,cost=p.ss;
        if(dist[u]<cost)continue;
        for(ll v=0;v<vec[u].size();v++){
            pll x=vec[u][v];
            if(dist[x.ff]>cost+x.ss){
                dist[x.ff]=cost+x.ss;
                que.push({x.ff,dist[x.ff]});
            }
        }
    }
}
int main()
{
    fastio
    cin>>n;
    for(int i=1;i<=n-1;i++){
        cin>>a>>b>>c;
        vec[a].pb({b,c});
        vec[b].pb({a,c});
    }
    cin>>q>>k;
    dijkstra(k);
    while(q--){
        cin>>a>>b;
        cout<<dist[a]+dist[b]<<endl;
    }
    return 0;
}
