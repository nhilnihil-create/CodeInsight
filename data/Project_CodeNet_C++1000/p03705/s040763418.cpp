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
  long long a, b;
  cin >> n >> a >> b;
  if (n == 1) {
    if (a == b) {
      cout << 1 << '\n';
    } else {
      cout << 0 << '\n';
    }
  } else {
    long long MIN = a + b + a * (n - 2);
    long long MAX = a + b + b * (n - 2);
    if (MAX >= MIN) {
      cout << MAX - MIN + 1 << '\n';
    } else {
      cout << 0 << '\n';
    }
  }
  return 0;
}