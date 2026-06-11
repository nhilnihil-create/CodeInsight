/**
 *    author:  tourist
 *    created: 27.01.2020 05:43:19       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long i, o, t, j, l, s, z;
  cin >> i >> o >> t >> j >> l >> s >> z;
  long long ans = o;
  if (i > 0 && j > 0 && l > 0 && i % 2 + j % 2 + l % 2 >= 2) {
    ans += 3;
    --i; --j; --l;
  }
  ans += 2 * (i / 2);
  ans += 2 * (j / 2);
  ans += 2 * (l / 2);
  cout << ans << '\n';
  return 0;
}
