#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
  int weight;
  Edge(int t, int w) : to(t), weight(w) {}
};
using ll = long long;
ll depth[100010];
using Graph = vector<vector<Edge>>;

void dfs(Graph &graph, int currentPoint, int parentPoint, ll totalWeight) {
  depth[currentPoint] = totalWeight;

  for (int i = 0; i < graph[currentPoint].size(); i++) {
    Edge e = graph[currentPoint][i];
    if (e.to == parentPoint) continue;

    dfs(graph, e.to, currentPoint, totalWeight + e.weight);
  }
}

// see: https://qiita.com/drken/items/4a7869c5e304883f539b
int main() {
  int N;
  cin >> N;

  Graph graph(N);

  for (int i = 0; i < N - 1; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    from--, to--;

    graph[from].push_back(Edge(to, weight));
    graph[to].push_back(Edge(from, weight));
  }

  int Q, K;
  cin >> Q >> K;

  // K から from, to までのスコアを計算
  dfs(graph, K - 1, -1, 0);

  for (int i = 0; i < Q; i++) {
    int from, to;
    cin >> from >> to;
    from--, to--;

    cout << (depth[from] + depth[to]) << endl;
  }
}