#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  cout << max(a * b, c * d) << '\n';

  return (0);
}
