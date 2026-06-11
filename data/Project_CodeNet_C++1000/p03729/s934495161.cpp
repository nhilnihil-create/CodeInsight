#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string a, b, c;
  cin >> a >> b >> c;

  if (a.back() == b.front() && b.back() == c.front()) cout << "YES\n";
  else cout << "NO\n";

  return (0);
}
