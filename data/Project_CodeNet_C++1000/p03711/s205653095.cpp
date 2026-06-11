#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int g[] = { 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1 };
  int x, y;
  cin >> x >> y;

  if (g[x-1] == g[y-1]) cout << "Yes\n";
  else cout << "No\n";

  return (0);
}
