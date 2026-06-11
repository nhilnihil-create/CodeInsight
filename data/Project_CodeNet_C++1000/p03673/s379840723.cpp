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

  int64_t N;
  cin >> N;
  list<int64_t> B;
  bool is_inv = 0;
  for (int64_t i = 0; i < N; ++i) {
    int64_t a;
    cin >> a;
    if (!is_inv) {
      B.push_back(a);
    } else {
      B.push_front(a);
    }
    is_inv = 1 - is_inv;
  }
  if (!is_inv) {
    bool is_first = true;
    auto itr = B.begin();
    while (itr != B.end()) {
      if (!is_first) {
        cout << " ";
      }
      cout << *itr;
      is_first = false;
      ++itr;
    }
    cout << endl;

  } else {
    bool is_first = true;
    auto itr = B.rbegin();
    while (itr != B.rend()) {
      if (!is_first) {
        cout << " ";
      }
      cout << *itr;
      is_first = false;
      ++itr;
    }
    cout << endl;
  }
  return 0;
}
