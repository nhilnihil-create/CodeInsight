/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int32_t N, A, B;
  string S;
  cin >> N >> A >> B >> S;
  int32_t count = 0;
  int32_t rank_abroad = 0;

  const int32_t length = static_cast<int32_t>(S.length());
  for (int32_t i = 0; i < length; ++i) {
    switch (S.c_str()[i]) {
      case 'a':
        if (count < A + B) {
          cout << "Yes" << endl;
          ++count;
        } else {
          cout << "No" << endl;
        }
        break;
      case 'b':
        ++rank_abroad;
        if (count < A + B && rank_abroad <= B) {
          cout << "Yes" << endl;
          ++count;
        } else {
          cout << "No" << endl;
        }
        break;
      default:
        cout << "No" << endl;
        break;
    }
  }
  return 0;
}
