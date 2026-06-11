#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<int, int>;

int main() {
  ll a, b, x;
  cin >> a >> b >> x;

  ll r = b / x;
  ll l = a / x;
  ll ans = r - l;

  if (a % x == 0) ans++;
  cout << ans << endl;
}
