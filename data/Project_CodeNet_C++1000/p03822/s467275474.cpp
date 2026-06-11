#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

template<class T> inline bool UpdateMin(T& a, T b) {
  if (a > b) { a = b; return 1; } return 0;
}
template<class T> inline bool UpdateMax(T& a, T b) {
  if (a < b) { a = b; return 1; } return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<vector<int>> graph(n);
  for (int i = 1; i < n; i++) {
    int a;
    cin >> a;
    a--;
    graph[a].push_back(i);
  }

  function<int(int)> dfs_fn = [&](int v) -> int {
    if (graph[v].empty()) return 0;
    int depth = graph[v].size();
    vector<int> values;
    for (int c : graph[v]) {
      values.push_back(dfs_fn(c));
    }
    sort(values.begin(), values.end());
    reverse(values.begin(), values.end());
    for (int i = 0; i < values.size(); i++) {
      UpdateMax(depth, i + 1 + values[i]);
    }
    // cout << "v: " << v << " depth: " << depth << endl;
    return depth;
  };
  cout << dfs_fn(0) << endl;
}