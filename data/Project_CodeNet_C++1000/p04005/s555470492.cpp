#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll ans;
  if (a % 2 == 0) ans = 0;
  else if (b % 2 == 0) ans = 0;
  else if (c % 2 == 0) ans = 0;
  else ans = min(a * b, min(a * c, b * c));
  cout << ans << endl;
  return 0;
}
