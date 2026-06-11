#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void()
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y;
  cin >> x >> y;
  int ans = 2 * (int)1e9;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      int a = x, b = y, cnt = 0;
      if (i && j) {
        a = -a;
        b = -b;
        cnt = 2;
      } else if (i) {
        a = -a;
        cnt = 1;
      } else if (j) {
        b = -b;
        cnt = 1;
      }
      if (b - a >= 0) {
        ans = min(ans, cnt + b - a);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}