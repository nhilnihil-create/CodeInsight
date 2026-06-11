#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll x, y;
  cin >> x >> y;
  ll ans;
  if (x * y > 0) {
    if (x <= y) ans = y - x;
    else ans = x - y + 2;
  } else if (x * y < 0) {
    ans = abs(abs(x) - abs(y)) + 1;
  } else if (x > y) {
    ans = x - y + 1;
  } else {
    ans = -x + y;
  }
  cout << ans << endl;
  return 0;
}