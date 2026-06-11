#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  int cur = 1;
  long long ans = 0;
  int a;
  cin >> a;
  ans += a - 1;
  for (int i = 1; i < n; i++) {
    cin >> a;
    if (a <= cur) continue;
    if (cur + 1 == a) {
      cur++;
      continue;
    }
    ans += (a - 1) / (cur + 1);
  }
  cout << ans << '\n';
  return 0;
}