/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t A, B, C;
  cin >> A >> B >> C;
  int64_t count;
  constexpr int32_t kMaxCount = 100000;
  for (int64_t i = 0; i < kMaxCount; ++i) {
    count = i;
    if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
      break;
    }
    const int32_t temp_a = A, temp_b = B, temp_c = C;
    A = temp_b / 2 + temp_c / 2;
    B = temp_a / 2 + temp_c / 2;
    C = temp_a / 2 + temp_b / 2;
  }
  if (count == kMaxCount - 1) {
    cout << -1 << endl;
  } else {
    cout << count << endl;
  }

  return 0;
}
