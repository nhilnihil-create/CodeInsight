#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge { int to; ll cost; };
vector<Edge> G[2010];
ll INF = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int V, E; cin >> V >> E;
  vector<ll> d(V, INF);

  for (int i = 0; i < E; i++) {
    int a, b; cin >> a >> b; a--; b--;
    ll c; cin >> c;
    G[a].emplace_back(Edge({b, -c}));
    // G[b].emplace_back(Edge({a, -c}));
  }

  d[0] = 0;
  for (int t = 0; t < V * 2; t++) {
    for (int i = 0; i < V; i++) {
      if (d[i] == INF) continue;
      for (auto e: G[i]) {
        if (d[e.to] > d[i] + e.cost) {
          d[e.to] = d[i] + e.cost;
          if (t == V - 1) {
            d[e.to] = -INF;
          }
        }
      }
    }
  }

  if (d[V - 1] <= -INF) cout << "inf\n";
  else cout << -d[V - 1] << '\n';

  return 0;
}