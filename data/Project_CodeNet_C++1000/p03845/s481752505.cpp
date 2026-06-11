/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N;
  cin >> N;
  vector<int64_t> T(N);
  int64_t total_time = 0;
  for (int64_t i = 0; i < N; ++i) {
    cin >> T[i];
    total_time += T[i];
  }
  int64_t M;
  cin >> M;
  for (int64_t i = 0; i < M; ++i) {
    int64_t p, x;
    cin >> p >> x;
    cout << (total_time - T[p - 1] + x) << endl;
  }

  return 0;
}
