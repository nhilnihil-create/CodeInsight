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
  int w, h, n;
  cin >> w >> h >> n;
  vector<vector<bool>> c(w, vector<bool>(h, true));
  while (n--) {
    int x, y, a;
    cin >> x >> y >> a;
    x--, y--;
    if (a == 1) {
      for (int i = 0; i <= x; i++) {
        for (int j = 0; j < h; j++) {
          c[i][j] = false;
        }
      }
    } else if (a == 2) {
      for (int i = x + 1; i < w; i++) {
        for (int j = 0; j < h; j++) {
          c[i][j] = false;
        }
      }
    } else if (a == 3) {
      for (int i = 0; i < w; i++) {
        for (int j = 0; j <= y; j++) {
          c[i][j] = false;
        }
      }
    } else {
      for (int i = 0; i < w; i++) {
        for (int j = y + 1; j < h; j++) {
          c[i][j] = false;
        }
      }
    }
    debug(c);
  }
  int ans = 0;
  for (int i = 0; i < w; i++) {
    for (int j = 0; j < h; j++) {
      ans += c[i][j];
    }
  }
  cout << ans << '\n';
  return 0;
}