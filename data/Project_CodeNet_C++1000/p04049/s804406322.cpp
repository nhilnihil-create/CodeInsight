#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2001;
vector<ll> g[N];
int dis[2001][2001];
vector<pair<ll,ll>> edges;
vector<bool> vis(2001);
void dfs(int start){
    queue<ll> q;
    fill(vis.begin(),vis.end(),false);
    q.push(start);
    vis[start]=true;
    dis[start][start]=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i:g[cur]){
            if(vis[i]) continue;
            q.push(i);
            vis[i]=true;
            dis[start][i]=1+dis[start][cur];
        }
    }
}
int main(){
    ll n,k;
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        edges.push_back({x,y});
    }
   for(int i=1;i<=n;i++) dfs(i);
    if(k%2==0){
        ll ans=1e16;
        for(int i=1;i<=n;i++){
            ll cnt=0;
            for(int j=1;j<=n;j++){
                if(dis[i][j]>k/2) cnt++;
            }
            ans=min(ans,cnt);
        }
        cout<<ans<<endl;
    }
    else{
        ll ans=1e16;
        k--;
        for(int i=0;i<edges.size();i++){
            ll cnt=0;
            for(int j=1;j<=n;j++){
                if(dis[edges[i].first][j]>k/2 && dis[edges[i].second][j]>k/2) cnt++;
            }
            ans=min(ans,cnt);
        }
        cout<<ans<<endl;
    }
    return 0;
}
