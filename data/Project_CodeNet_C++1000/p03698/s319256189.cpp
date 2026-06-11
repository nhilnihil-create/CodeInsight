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

  string S;
  cin >> S;
  const int32_t length = static_cast<int32_t>(S.length());
  vector<int32_t> lookup(256, 0);
  bool okay = true;
  for (int32_t i = 0; i < length; ++i) {
    lookup[S.c_str()[i]]++;
    if (lookup[S.c_str()[i]] >= 2) {
      okay = false;
      break;
    }
  }
  if (okay) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }

  return 0;
}
