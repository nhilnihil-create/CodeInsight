#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  vector<int> diff(n);
  rep(i, n) {
    if (i == 0) {
      diff.at(i) = 0;
    } else {
      diff.at(i) = a.at(i) - a.at(i - 1);
    }
  }
  int res = 0;
  bool isIncrement = false;
  bool initialized = false;
  for (int i = 1; i < n; i++) {
    int d = diff.at(i);
    if (d > 0) {
      if (!initialized) {
        isIncrement = true;
        initialized = true;
        continue;
      }
      if (!isIncrement) {
        res++;
        isIncrement = true;
        initialized = false;
      }
    } else if (d < 0) {
      if (!initialized) {
        isIncrement = false;
        initialized = true;
        continue;
      }
      if (isIncrement) {
        res++;
        isIncrement = false;
        initialized = false;
      }
    } else {
      // 処理なし
    }
  }
  res++;
  cout << res << endl;
  return 0;
}
