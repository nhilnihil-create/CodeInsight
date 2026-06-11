#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  int ans = 2100000000;
  if (y >= x) ans = min(ans, y - x);
  if (y >= -x) ans = min(ans, y + x + 1);
  if (-y >= x) ans = min(ans, -y - x + 1);
  if (-y >= -x) ans = min(ans, -y + x + 2);
  cout << ans << endl;
}