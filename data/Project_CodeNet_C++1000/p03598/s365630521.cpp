#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  int ans = 0;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;

    int a = x;
    int b = k - x;

    int c = min(a, b);
    ans += 2 * c;
  }

  cout << ans << '\n';

  return (0);
}