#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll x, y;
  cin >> x >> y;
  ll ans = (1LL << 31) - 1;

  ll x_inv = x * -1;
  ll y_inv = y * -1;

  if (x <= y) ans = min(ans, y - x);
  if (x <= y_inv) ans = min(ans, y_inv - x + 1);
  if (x_inv <= y) ans = min(ans, y - x_inv + 1);
  if (x_inv <= y_inv) ans = min(ans, y_inv - x_inv + 2);

  cout << ans << endl;
  return 0;
}
