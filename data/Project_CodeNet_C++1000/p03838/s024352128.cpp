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
  int inf = 2 * (int)1e9;
  cout << min({(y - x >= 0 ? y - x : inf), (1 + y + x >= 0 ? 1 + y + x : inf),
               (1 - y - x >= 0 ? 1 - y - x : inf),
               (2 + x - y >= 0 ? 2 + x - y : inf)})
       << '\n';
  return 0;
}