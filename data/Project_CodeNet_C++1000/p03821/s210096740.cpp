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
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  long long ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    a[i] += ans;
    int rest = a[i] % b[i];
    if (rest > 0) ans += b[i] - rest;
    debug(ans);
  }
  cout << ans << '\n';
  return 0;
}