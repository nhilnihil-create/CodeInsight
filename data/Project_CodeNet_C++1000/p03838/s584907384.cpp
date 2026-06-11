#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int x, y;
  cin >> x >> y;

  bool isSameSign = (x > 0 && y > 0) || (x < 0 && y < 0);
  int res = 0;
  res += abs(abs(y) - abs(x));
  if (y == 0) {
    if (x > 0) {
      res++;
    }
  } else if (x == 0) {
    if (y < 0) {
      res++;
    }
  } else if (isSameSign) {
    if (x > y) {
      res += 2;
    }
  } else {
    res++;
  }
  cout << res << endl;

  return 0;
}
