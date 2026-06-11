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
  long long n, ans;
  cin >> n >> ans;
  while (--n) {
    long long a;
    cin >> a;
    ans = lcm(ans, a);
  }
  cout << ans << '\n';
  return 0;
}