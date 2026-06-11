#include <bits/stdc++.h>

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> g(n);
  vector<int> from(n), to(n);
  for (int i = 0; i + 1 < n; i++) {
    cin >> from[i] >> to[i];
    from[i]--; to[i]--;
    g[from[i]].push_back(to[i]);
    g[to[i]].push_back(from[i]);
  }
  vector<int> depth(n);
  vector<int> size(n);
  vector<int> parent(n);
  function<void(int, int, int)> dfs = [&](int v, int pv, int d) {
    depth[v] = d;
    size[v] = 1;
    parent[v] = pv;
    for (int u : g[v]) {
      if (u == pv) {
        continue;
      }
      dfs(u, v, d + 1);
      size[v] += size[u];
    }
  };
  int ans = n;
  if (k % 2 == 0) {
    for (int i = 0; i < n; i++) {
      dfs(i, -1, 0);
      int sum = 0;
      for (int j = 0; j < n; j++) {
        if (depth[j] == k / 2) {
          sum += size[j] - 1;
        }
      }
      ans = min(ans, sum);
    }
  } else {
    for (int i = 0; i + 1 < n; i++) {
      dfs(from[i], to[i], 0);
      dfs(to[i], from[i], 0);
      int sum = 0;
      for (int j = 0; j < n; j++) {
        if (depth[j] == (k - 1) / 2) {
          sum += size[j] - 1;
        }
      }
      ans = min(ans, sum);
    }
  }
  cout << ans << '\n';
  return 0;
}