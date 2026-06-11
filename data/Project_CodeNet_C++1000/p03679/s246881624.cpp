#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x, a, b;
  cin >> x >> a >> b;

  int c = b - a;
  if (c <= 0) cout << "delicious\n";
  else if (c > x) cout << "dangerous\n";
  else cout << "safe\n";

  return (0);
}
