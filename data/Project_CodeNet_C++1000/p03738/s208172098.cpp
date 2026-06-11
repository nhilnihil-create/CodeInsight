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

  string A, B;
  cin >> A >> B;
  enum class Comparison : int32_t { kEquals = 0, kGreater, kLess };
  Comparison result;
  if (A.length() > B.length()) {
    result = Comparison::kGreater;
  } else if (A.length() < B.length()) {
    result = Comparison::kLess;
  } else {
    const int32_t length = static_cast<int32_t>(A.length());
    for (int32_t i = 0; i < length; ++i) {
      if (A.c_str()[i] > B.c_str()[i]) {
        result = Comparison::kGreater;
        break;
      } else if (A.c_str()[i] < B.c_str()[i]) {
        result = Comparison::kLess;
        break;
      } else {
        result = Comparison::kEquals;
      }
    }
  }

  switch (result) {
    case Comparison::kEquals:
      cout << "EQUAL" << endl;
      break;
    case Comparison::kGreater:
      cout << "GREATER" << endl;
      break;
    default:
      cout << "LESS" << endl;
      break;
  }

  return 0;
}
