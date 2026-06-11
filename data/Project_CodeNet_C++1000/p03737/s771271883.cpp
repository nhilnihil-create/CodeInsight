#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string a, b, c;
  cin >> a >> b >> c;

  string ans;
  ans += a[0] - 32;
  ans += b[0] - 32;
  ans += c[0] - 32;
  
  cout << ans << '\n';

  return (0);
}
