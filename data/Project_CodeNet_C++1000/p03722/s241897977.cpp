#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
const ll INF = 1e18;
struct edge {int from,to;ll cost;};
using E = vector<edge>;

vector<ll> Bellman_ford(const E &edges, int v, int s) {
  vector<ll> dist(v,INF);
  dist[s] = 0;
  rep(i,v) {
    for (auto e : edges) {
      if (dist[e.from] == INF) continue;
      if (dist[e.to] > dist[e.from] + e.cost) dist[e.to] = dist[e.from] + e.cost;
    }
  }
  return dist;
}

int main(){
  E G;
  int n,m;
  cin >> n >> m;
  rep(i,m) {
    int a, b, c;
    cin >> a >> b >> c;
    --a;--b;
    G.push_back(edge{a,b,-c});
  }
  auto dist = Bellman_ford(G,n,0);

  //1~nの最短経路上に負閉路があるか
  rep(i,n) {
    rep(j,sz(G)) {
      edge e = G[j];
      if (dist[e.from] == INF) continue;
      if (dist[e.to] > dist[e.from] + e.cost) dist[e.to] = -INF;
    }
  }

  if(dist[n-1] == -INF) puts("inf");
  else cout << -dist[n-1] << endl;
 
  return 0;
}