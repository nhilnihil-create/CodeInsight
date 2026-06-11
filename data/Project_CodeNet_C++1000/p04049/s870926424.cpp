#include <bits/stdc++.h>

using namespace std;

const int N = 6969;

int n, k, h[N];
vector <int> g[N];

void dfs (int u, int pr = -1, int far = 0) {
  h[u] = far;
  for (int v : g[u]) if (v ^ pr) dfs(v, u, far + 1);
}

int main() {
  cin >> n >> k;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  int ans = n;
  if (k & 1) {
    for (int u = 1; u <= n; ++u) for (int v : g[u]) {
      dfs(u, v); dfs(v, u);
      int cur = 0;
      for (int i = 1; i <= n; ++i) {
        if (h[i] > k / 2) ++cur;
      }
      ans = min(ans, cur);
    }
  } else {
    for (int cen = 1; cen <= n; ++cen) {
      dfs(cen);
      int cur = 0;
      for (int i = 1; i <= n; ++i) {
        if (h[i] > k / 2) ++cur;
      }
      ans = min(ans, cur);
    }
  }
  cout << ans << '\n';
  return 0;
}

