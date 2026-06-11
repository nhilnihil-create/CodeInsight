#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

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

  function<int64(int, int)> dfs = [&](int v, int p) -> int64 {
    vector<int> cs;
    for (const auto& e : graph[v]) {
      if (e.to == p) continue;
      cs.push_back(e.to);
    }
    if (cs.size() == 0) {
      return xs[v];
    }

    int64 value_sum = 0;
    for (int c : cs) {
      int64 value = dfs(c, v);
      if (value < 0) return -1;
      if (value > xs[v]) return -1;
      value_sum += value;
    }
    if (value_sum > xs[v] * 2) return -1;
    if (xs[v] * 2 - value_sum > xs[v]) return -1;
    return xs[v] * 2 - value_sum;
  };
  for (int r = 0; r < n; r++) {
    if (graph[r].size() == 1) {
      int64 dfs_value = dfs(graph[r][0].to, r);
      if (dfs_value < 0 || dfs_value != xs[r]) {
        cout << "NO" << endl;
      } else {
        cout << "YES" << endl;
      }
      return 0;
    }
  }
}