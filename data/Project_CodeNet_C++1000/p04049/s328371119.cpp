#include<bits/stdc++.h>
using namespace std;
int main() {
  int V, K; cin >> V >> K;
  vector<vector<int>> g(V);
  for (int i = 0; i < V-1; i++) {
    int u, v; cin >> u >> v; u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int res = V;
  auto dfs = [&](auto f, int n, int p, int d) -> int {
    if (d == 0) return 0;
    int cnt = 1;
    for (auto x : g[n]) {
      if (x == p) continue;
      cnt += f(f, x, n, d-1);
    }
    return cnt;
  };
  for (int i = 0; i < V; i++) {
    if (K % 2 == 0) res = min(res, V - dfs(dfs, i, -1, K/2+1));
    else {
      for (auto x : g[i]) {
        res = min(res, V - dfs(dfs, i, x, K/2+1) - dfs(dfs, x, i, K/2+1));
      }
    }
  }
  cout << res << endl;
}