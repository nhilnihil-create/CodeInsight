#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<pair<int, int>>> edges(N, vector<pair<int, int>>());
  for (int i = 0; i < N - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    edges[a].push_back({b, c});
    edges[b].push_back({a, c});
  }
  int Q, K;
  cin >> Q >> K;
  K--;
  vector<int> X(Q), Y(Q);
  for (int i = 0; i < Q; i++) {
    cin >> X[i] >> Y[i];
    X[i]--;
    Y[i]--;
  }
  vector<long long> D(N, -1);
  D[K] = 0;
  queue<int> que;
  que.push(K);
  while (!que.empty()) {
    auto p = que.front();
    que.pop();
    for (auto e : edges[p]) {
      if (D[e.first] != -1) continue;
      D[e.first] = D[p] + e.second;
      que.push(e.first);
    }
  }
  for (int i = 0; i < Q; i++) {
    long long ans = D[X[i]] + D[Y[i]];
    cout << ans << endl;
  }

  return 0;
}
/* vim:set fdm=marker: */
