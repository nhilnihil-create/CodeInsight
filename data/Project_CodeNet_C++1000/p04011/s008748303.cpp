#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k, x, y;
  cin >> n >> k >> x >> y;

  int ans = 0;
  ans += x * min(n, k);
  ans += max(0, y * (n - k));

  cout << ans << '\n';

  return (0);
}
