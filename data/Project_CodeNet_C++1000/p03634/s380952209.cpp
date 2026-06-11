#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<vector<pair<int, int64_t>>> G(N + 1);
  rep(i, N - 1) {
    int a, b, c;
    cin >> a >> b >> c;
    G[a].emplace_back(b, c);
    G[b].emplace_back(a, c);
  }
  int Q, K;
  cin >> Q >> K;

  // dijkstra
  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>,
                 greater<pair<int64_t, int>>>
      que;
  que.emplace(0, K);
  vector<int64_t> D(N + 1, INT64_MAX);
  D[K] = 0;
  while (!que.empty()) {
    int64_t dist;
    int v;
    tie(dist, v) = que.top();
    que.pop();
    if (D[v] < dist) continue;

    for (auto& nv : G[v]) {
      int64_t ndist = dist + nv.second;
      if (D[nv.first] <= ndist) continue;
      D[nv.first] = ndist;
      que.emplace(ndist, nv.first);
    }
  }

  rep(i, Q) {
    int x, y;
    cin >> x >> y;
    cout << D[x] + D[y] << endl;
  }
  return 0;
}