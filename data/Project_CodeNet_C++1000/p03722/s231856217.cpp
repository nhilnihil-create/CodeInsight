#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using Edge = pair<int, ll>;
vector<vector<Edge>> G;
ll INF = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int V, E; cin >> V >> E;
  G.resize(V);
  vector<ll> d(V, INF);

  for (int i = 0; i < E; i++) {
    int a, b; cin >> a >> b; a--; b--;
    ll c; cin >> c;
    G[a].emplace_back(Edge(b, -c));
    // G[b].emplace_back(a);
  }

  d[0] = 0;
  for (int t = 0; t < V * 2; t++) {
    for (int i = 0; i < V; i++) {
      if (d[i] == INF) continue;
      for (auto e: G[i]) {
        if (d[e.first] > d[i] + e.second) {
          d[e.first] = d[i] + e.second;
          if (t == V -1) {
            d[e.first] = -INF;
          }
        }
      }
    }
  }

  if (d[V - 1] <= -INF) cout << "inf\n";
  else cout << -d[V - 1] << '\n';

  return 0;
}