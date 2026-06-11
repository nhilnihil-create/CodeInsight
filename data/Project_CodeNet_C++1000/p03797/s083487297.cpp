#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll mod = 1e9 + 7;

int main() {
  ll s, c;
  cin >> s >> c;
  ll ans = 0;
  while (s >= 1 && c >= 2) {
    if (min(s, c/2) == s) {
      ans += s;
      c -= 2*s;
      s = 0;
    } else {
      ans += c/2;
      s -= c/2;
      c %= 2;
    }
  }
  if (c >= 4) ans += c/4;
  cout << ans << endl;
  return 0;
}
