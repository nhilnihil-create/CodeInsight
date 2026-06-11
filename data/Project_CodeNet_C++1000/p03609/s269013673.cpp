#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x, t;
  cin >> x >> t;

  cout << max(x - t, 0) << '\n';

  return (0);
}
