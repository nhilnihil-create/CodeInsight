#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int V, E;
ll cost[105][105];
ll INF = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll cost2[105][105];
  cin >> V >> E;
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (i == j) cost[i][j] = 0;
      else cost[i][j] = INF;
      cost2[i][j] = INF;
    }
  }

  for (ll i = 0; i < E; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    ll t; cin >> t;
    cost[a][b] = t;
    cost[b][a] = t;
    cost2[a][b] = t;
    cost2[b][a] = t;
  }

  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
      }
    }
  }

  ll ans = 0;
  for (ll i = 0; i < V; i++) {
    for (ll j = 0; j < V; j++) {
      if (i == j) continue;
      if (cost2[i][j] == INF) continue;
      if (cost[i][j] < cost2[i][j]) ans++;
    }
  }

  cout << ans / 2 << '\n';
  return 0;
}