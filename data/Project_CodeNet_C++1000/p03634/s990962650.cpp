#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 1e9+1;
const ll INFll = (ll)1e18+1;
ll MOD=1e9+7;


int main(){
  ll N;
  cin>>N;
  struct edge {ll to,cost;};
  vector<vector<edge>> G(N,vector<edge>());
  for(ll i(0);i<N-1;i++){
    ll a,b,c;
    cin>>a>>b>>c;
    a--;
    b--;
    G[a].push_back({b,c});
    G[b].push_back({a,c});
  }
  ll Q,K;
  cin>>Q>>K;
  K--;
  vector<ll> x(Q),y(Q);
  for(ll i(0);i<Q;i++){
    cin>>x[i]>>y[i];
    x[i]--;
    y[i]--;
  }

  vector<ll> d(N,INFll);
  d[K] = 0;

  // first: cont, second: node number 
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
  q.push({0,K});
  while(!q.empty()){
    pair<ll,ll> p = q.top();q.pop();
    ll v = p.second;
    if (d[v] < p.first) continue;
    for (ll i(0);i<ll(G[v].size());i++){
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        q.push({d[e.to],e.to});
      }
    }
  } 
  // for(ll i(0);i<N;i++){
  //   cout << d[i] << " ";
  // }
  // cout << endl;
  for(ll i(0);i<Q;i++){
    cout << d[x[i]] + d[y[i]] << endl;
  } 
  return 0;
}

