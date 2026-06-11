#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string n, m;
  cin >> n;

  m = n;
  reverse(m.begin(), m.end());

  if (m == n) cout << "Yes\n";
  else cout << "No\n";

  return (0);
}
