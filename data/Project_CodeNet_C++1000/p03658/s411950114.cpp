#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  int l[n];
  for (int i = 0; i < n; ++i) cin >> l[i];
  
  sort(l, l+n, greater<int>());
  int ans = 0;

  for (int i = 0; i < k; ++i) ans += l[i];
  cout << ans << '\n';

  return (0);
}
