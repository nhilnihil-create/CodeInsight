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

  int32_t N;
  cin >> N;

  constexpr int32_t kMaxNumberOfColor = 8;

  vector<int32_t> color_count(kMaxNumberOfColor, 0);
  int32_t joker = 0;
  for (int32_t i = 0; i < N; ++i) {
    int32_t a;
    cin >> a;
    if (a < 3200) {
      ++color_count[a / 400];
    } else {
      ++joker;
    }
  }
  int32_t number_of_colors = 0;
  for (const int32_t count : color_count) {
    if (count > 0) {
      number_of_colors++;
    }
  }
  cout << max(1, number_of_colors) << " " << number_of_colors + joker << endl;

  return 0;
}
