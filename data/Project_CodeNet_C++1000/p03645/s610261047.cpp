#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> G(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  function<bool(int, int)> f = [&](int u, int c) {
    if (c == 2) return false;
    bool res = false;
    for (int v : G[u]) {
      if (v == N - 1) {
        cout << "POSSIBLE" << '\n';
        exit(0);
      }
      f(v, c + 1);
    }
    return false;
  };

  if (f(0, 0)) {
    cout << "POSSIBLE" << '\n';
  } else {
    cout << "IMPOSSIBLE" << '\n';
  }
  return 0;
}
