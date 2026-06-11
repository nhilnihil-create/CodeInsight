#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  long long i, o, t, j, l, s, z;
  cin >> i >> o >> t >> j >> l >> s >> z;
  long long ans = l / 2 * 2 + j / 2 * 2 + i / 2 * 2 + o;
  if (l >= 1 && j >= 1 && i >= 1) {
    ans = max(ans, (l - 1) / 2 * 2 + (j - 1) / 2 * 2 + (i - 1) / 2 * 2 + 3 + o);
  }
  cout << ans << '\n';
  return 0;
}