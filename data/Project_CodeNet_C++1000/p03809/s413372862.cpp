#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

struct Edge {
  const int from, to;
  Edge(int from, int to) : from(from), to(to) {}
};

vector<vector<Edge>> ReadUndirectedGraph(
    int n, int m, bool is_one_indexed=false) {
  vector<vector<Edge>> graph(n);
  for (int i = 0; i < m; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    if (is_one_indexed) {
      v1--;
      v2--;
    }
    graph[v1].push_back(Edge(v1, v2));
    graph[v2].push_back(Edge(v2, v1));
  }
  return graph;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int64> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }

  auto graph = ReadUndirectedGraph(n, n - 1, true);

  int r = -1;
  for (int v = 0; v < n; v++) {
    if (graph[v].size() >= 2) {
      r = v;
      break;
    }
  }

  if (r == -1) {
    // n == 2
    if (n != 2) exit(1);
    cout << ((xs[0] == xs[1]) ? "YES" : "NO") << endl;
    return 0;
  }

  vector<int64> dp(n);
  function<bool(int, int)> dfs_fn = [&](int v, int p) -> bool {
    if (graph[v].size() == 1) {
      dp[v] = xs[v];
      return true;
    }

    int64 xc = 0;
    int64 xv = xs[v];
    for (const auto& e : graph[v]) {
      if (e.to == p) continue;
      if (!dfs_fn(e.to, v)) return false;
      xc += dp[e.to];
    }

    int64 a = xc - xv;
    int64 b = -xc + xv * 2;

    if (a < 0 || b < 0) return false;
    
    for (const auto& e : graph[v]) {
      if (e.to == p) continue;
      if (dp[e.to] > a + b) return false;
    }
    
    dp[v] = b;

    if (p < 0) return b == 0;

    return true;
  };
  bool ans = dfs_fn(r, -1);
  cout << (ans ? "YES" : "NO") << endl;
}