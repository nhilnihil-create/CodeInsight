#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

const ll INF = 1e15;

int main(){ 
  int n;
  cin>>n;
  vector<vector<pair<ll,int>>> g(n);
  rep(i,n-1){
    int a,b;
    ll c;
    cin>>a>>b>>c;
    a--; b--;
    g[a].pb({c,b});
    g[b].pb({c,a});
  }
  vector<ll> dist(n,INF);
  priority_queue<pair<ll,int>> que;
  
  int q,k;
  cin>>q>>k;
  k--;
  dist[k]=0;
  que.push({0,k});
  
  while(!que.empty()){
    int x = que.top().second;
    que.pop();
    
    for(auto nx:g[x]){
      if(dist[nx.second]<dist[x]+nx.first) continue;
      que.push({dist[x]+nx.first,nx.second});
      dist[nx.second] = dist[x]+nx.first;     
    }
  }
  rep(i,q){
    int x,y;
    cin>>x>>y;
    x--; y--;
    cout << dist[x]+dist[y] << endl;
  }
}