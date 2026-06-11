#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int d[3];
  cin >> d[0] >> d[1] >> d[2];
  sort(d, d+3);

  cout << d[0] + d[1] << '\n';

  return (0);
}
