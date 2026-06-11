#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int five = 0, seven = 0;

  for (int i = 0; i < 3; ++i) {
    int c;
    cin >> c;

    if (c == 7) ++seven;
    else if (c == 5) ++five;
  }

  if (five == 2 && seven == 1) cout << "YES\n";
  else cout << "NO\n";

  return (0);
}
