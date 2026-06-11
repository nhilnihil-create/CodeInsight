#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  ll x, y;
  cin >> x >> y;

  ll ans = 0;

  if (abs(x) > abs(y)) {
    if (x > 0) ans++;
    ans += abs(x) - abs(y);
    if (y > 0) ans++;
  } else if (abs(x) < abs(y)) {
    if (x < 0) ans++;
    ans += abs(y) - abs(x);
    if (y < 0) ans++;
  } else if (abs(x) == abs(y)) {
    if (x != y) ans++;
  }

  cout << ans << endl;
}
