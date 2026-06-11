#include<bits/stdc++.h>
using namespace std;
using lint = long long;

typedef pair<lint, lint> P;
vector<lint> dist;
const lint INF = 1e18;
struct  edge{lint to, cost;};
vector<edge> G[100010];

void dij(lint start){
  priority_queue<P, vector<P>, greater<P> > que;
  for(lint i = 0; i < dist.size(); i++) dist[i] = INF;
  dist[start] = 0;
  que.push(P(0, start));
  
  while(!que.empty()){
    P p = que.top(); que.pop();
    lint next = p.second;
    if(dist[next] < p.first) continue;
    for(lint i = 0; i < G[next].size(); i++){
      edge e = G[next][i];
      if(dist[next] + e.cost < dist[e.to]){
        dist[e.to] = dist[next] + e.cost;
        que.push(P(dist[e.to], e.to));
      }
    }
  }
}

signed main(){
  lint N; cin >> N;
  for(lint i = 0; i < N - 1; i++){
    lint a, b, c; cin >> a >> b >> c;
    edge e = {b - 1, c}, e1 = {a - 1, c};
    G[a - 1].push_back(e); G[b - 1].push_back(e1); 
  }
  dist.resize(N);
  lint Q, K; cin >> Q >> K;
  dij(K - 1);
  for(lint i = 0; i < Q; i++){
    lint x, y; cin >> x >> y;
    lint ans = dist[x - 1] + dist[y - 1];
    cout << ans << endl;
  }
}
  