#include<bits/stdc++.h>
using namespace std;
using lint = long long;

vector<lint> dist;
const lint INF = 1e18;
struct  edge{lint to, cost;};
vector<edge> G[100010];

void dfs(lint now, lint ago, lint depth){
  dist[now] = depth;
  for(lint i = 0; i < G[now].size(); i++){
    lint next = G[now][i].to;
    if(next == ago) continue;
    dfs(next, now, depth + G[now][i].cost);
  }
}

signed main(){
  lint N; cin >> N;
  for(lint i = 1; i < N; i++){
    lint a, b, c; cin >> a >> b >> c; --a; --b;
    G[a].push_back(edge{b, c}); G[b].push_back(edge{a, c});
  }
  dist.resize(N, 0);
  lint Q, K; cin >> Q >> K;
  dfs(K - 1, -1, 0);
  for(lint i = 0; i < Q; i++){
    lint x, y; cin >> x >> y;
    lint ans = dist[x - 1] + dist[y - 1];
    cout << ans << "\n";
  }
}
