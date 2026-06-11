#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

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

vector<vector<Edge>> ReadDirectedGraph(
    int n, int m, bool is_one_indexed=false) {
  vector<vector<Edge>> graph(n);
  for (int i = 0; i < m; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    if (is_one_indexed) {
      v1--;
      v2--;
    }
    graph[v1].push_back(Edge({v1, v2}));
  }
  return graph;
}

struct WeightedEdge {
  int from, to;
  int64 weight;
  WeightedEdge(int from, int to, int64 weight)
      : from(from), to(to), weight(weight) {}
};

// Verified: ABC126D
vector<vector<WeightedEdge>> ReadUndirectedWeightedGraph(
    int n, int m, bool is_one_indexed=false) {
  vector<vector<WeightedEdge>> graph(n);
  for (int i = 0; i < m; i++) {
    int v1, v2;
    int64 weight;
    cin >> v1 >> v2 >> weight;
    if (is_one_indexed) {
      v1--;
      v2--;
    }
    graph[v1].push_back(WeightedEdge(v1, v2, weight));
    graph[v2].push_back(WeightedEdge(v2, v1, weight));
  }
  return graph;
}

vector<vector<WeightedEdge>> ReadDirectedWeightedGraph(
    int n, int m, bool is_one_indexed=false) {
  vector<vector<WeightedEdge>> graph(n);
  for (int i = 0; i < m; i++) {
    int v1, v2;
    int64 weight;
    cin >> v1 >> v2 >> weight;
    if (is_one_indexed) {
      v1--;
      v2--;
    }
    graph[v1].push_back(WeightedEdge(v1, v2, weight));
  }
  return graph;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  auto graph = ReadUndirectedGraph(n, n - 1, true);
  function<int(int, int)> dfs = [&](int v, int p) -> int {
    if (graph[v].size() == 0) return 0;
    int value = 0;
    for (const auto& e : graph[v]) {
      if (e.to == p) continue;
      value ^= dfs(e.to, v) + 1;
    }
    return value;
  };
  int grundy = dfs(0, -1);
  if (grundy > 0) {
    cout << "Alice" << endl;
  } else {
    cout << "Bob" << endl;
  }
}