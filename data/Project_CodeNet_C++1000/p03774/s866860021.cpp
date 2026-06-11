/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int32_t N, M;
  cin >> N >> M;
  vector<Pair> students(N);
  vector<Pair> checkpoints(M);
  for (int32_t i = 0; i < N; ++i) {
    cin >> students[i].first >> students[i].second;
  }
  for (int32_t i = 0; i < M; ++i) {
    cin >> checkpoints[i].first >> checkpoints[i].second;
  }
  for (int32_t s = 0; s < N; ++s) {
    int32_t min_distance = INT32_MAX;
    int32_t nearest_checkpoint = -1;
    for (int32_t c = 0; c < M; ++c) {
      const int32_t distance =
          abs(students[s].first - checkpoints[c].first) + abs(students[s].second - checkpoints[c].second);
      if (distance < min_distance) {
        min_distance = distance;
        nearest_checkpoint = c + 1;
      }
    }
    cout << nearest_checkpoint << endl;
  }

  return 0;
}
