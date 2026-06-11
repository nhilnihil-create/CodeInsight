#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;

  if ((a + b) % 3 == 0 || a % 3 == 0 || b % 3 == 0) cout << "Possible\n";
  else cout << "Impossible\n";

  return (0);
}
