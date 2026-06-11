/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N, M;
  cin >> N >> M;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<vector<int64_t>> neighbours(N + 1, vector<int64_t>());
  for (int64_t i = 0; i < M; ++i) {
    int64_t a, b;
    cin >> a >> b;
    neighbours[a].emplace_back(b);
    neighbours[b].emplace_back(a);
  }
  vector<bool> visited(N + 1, false);
  queue<Pair> q;
  visited[1] = true;
  q.emplace(1, 0);
  while (!q.empty()) {
    const int64_t target = q.front().first;
    const int64_t count = q.front().second;
    q.pop();
    for (const auto &next : neighbours[target]) {
      if (!visited[next] && count + 1 <= 2) {
        visited[next] = true;
        q.emplace(next, count + 1);
      }
    }
  }
  if (visited[N]) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
