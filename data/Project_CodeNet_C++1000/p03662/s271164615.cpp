#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

// Vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  s << "[";
	for (int i = 0; i < len; i++) {
    if (i > 0) s << ", ";
		s << v[i];
  }
  s << "]";
  return s;
}

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

tuple<vector<int>, vector<int>>
BFS(const vector<vector<Edge>>& graph, int s) {
  int n = graph.size();

  deque<int> queue;
  queue.push_back(s);
  vector<int> ds(n, INT_MAX);
  vector<int> ps(n, -1);
  ds[s] = 0;
  while (!queue.empty()) {
    int v = queue.front();
    queue.pop_front();
    for (const auto& e : graph[v]) {
      if (ds[e.to] < INT_MAX) continue;
      ds[e.to] = ds[v] + 1;
      ps[e.to] = v;
      queue.push_back(e.to);
    }
  }
  return make_tuple(ds, ps);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  auto graph = ReadUndirectedGraph(n, n - 1, true);
  vector<int> ds, ps;
  tie(ds, ps) = BFS(graph, 0);

  vector<int> path;
  int v = n - 1;
  while (v != 0) {
    path.push_back(v);
    v = ps[v];
  }
  path.push_back(0);
  reverse(path.begin(), path.end());
  if (DEBUG) cout << "path: " << path << endl;
  int w = path[(path.size() + 1) / 2];
  if (DEBUG) cout << "w: " << w << endl;

  vector<int> visited(n, 0);
  function<void(int, int)> dfs_fn = [&](int v, int p) {
    visited[v] = 1;
    for (const auto& e : graph[v]) {
      if (e.to == p) continue;
      if (e.to == w) continue;
      if (visited[e.to]) continue;
      dfs_fn(e.to, v);
    }
  };
  dfs_fn(0, -1);

  int count = 0;
  for (int b : visited) {
    if (b) count++;
  }
  if (2 * count > n) {
    cout << "Fennec" << endl;
  } else {
    cout << "Snuke" << endl;
  }
}