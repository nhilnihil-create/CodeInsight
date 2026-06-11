#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> sz(n, 1), depth(n), parent(n);

  function<void(int,int)> dfs = [&](int u, int pa) {
    parent[u] = pa;
    if (pa != -1) {
      depth[u] = depth[pa] + 1;
    }
    for (auto v : g[u]) {
      if (v == pa) continue;
      dfs(v, u);
      sz[u] += sz[v];
    }
  };

  dfs(0, -1);
  int v = n - 1;
  for (int i = 0; i < (depth[n - 1] - 1) / 2; i++) {
   v = parent[v];
  }
  
  int x = n - sz[v], y = sz[v];
  cout << (x > y ? "Fennec" : "Snuke") << '\n';  

  return 0;
}
