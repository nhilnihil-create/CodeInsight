#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  int a, b, c;
  cin >> a >> b >> c;

  if (a == b && b == c) {
    if (a & 1) cout << '0' << '\n';
    else cout << -1 << '\n';
    
    return (0);
  }

  int ans = 0;

  while (1) {
    if ((a & 1) || (b & 1) || (c & 1)) break;

    int a2 = a, b2 = b, c2 = c;
    a = b2/2 + c2/2;
    b = a2/2 + c2/2;
    c = a2/2 + b2/2;

    ++ans;
  }

  cout << ans << '\n';

  return (0);
}
