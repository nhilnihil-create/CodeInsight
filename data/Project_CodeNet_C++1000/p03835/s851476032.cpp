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
  int k, s;
  cin >> k >> s;
  int ans = 0;
  for (int x = 0; x <= k; x++) {
    for (int y = 0; y <= k; y++) {
      int z = s - x - y;
      if (z < 0 || z > k) continue;
      ans++;
    }
  }
  cout << ans << '\n';
  return 0;
}