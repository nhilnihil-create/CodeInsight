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
  int n, m, k;
  cin >> n >> m >> k;
  bool good = false;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      int num = i * m + j * (n - i) - j * i;
      if (num == k) {
        good = true;
        break;
      }
    }
  }
  if (good) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
  return 0;
}