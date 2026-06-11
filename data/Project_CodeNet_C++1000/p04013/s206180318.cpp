#include <iostream>
#include <vector>
using namespace std;

using int64 = long long;

int main() {
  int64 n, a;
  cin >> n >> a;
  vector<int64> xs(n);
  for (int64& x : xs)
    cin >> x;

  static constexpr int64 kBase = 2510;
  vector<int64> more(kBase, 0);
  vector<int64> less(kBase, 0);
  more[0] = 1;
  less[0] = 1;
  int64 even = 0;
  for (int64 x : xs) {
    if (x < a) {
      int64 d = a - x;
      for (int64 i = less.size() - d - 1; i >= 0; --i) {
        less[i + d] += less[i];
      }
    } else if (x > a) {
      int64 d = x - a;
      for (int64 i = more.size() - d - 1; i >= 0; --i) {
        more[i + d] += more[i];
      }
    } else {
      ++even;
    }
  }

  int64 ret = 0;
  for (int64 i = 1; i < kBase; ++i) {
    ret += more[i] * less[i];
  }
  ret <<= even;
  ret += (1LL << even) - 1;
  cout << ret << "\n";

  return 0;
}
