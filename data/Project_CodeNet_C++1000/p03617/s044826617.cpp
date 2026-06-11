#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll q, h, s, d, n;
  cin >> q >> h >> s >> d >> n;

  ll min025 = q;
  ll min050 = min(min025 * 2, h);
  ll min100 = min(min050 * 2, s);
  ll min200 = min(min100 * 2, d);

  ll ans;
  if (n & 1) {
    ans = n / 2 * min(min100 * 2, min200) + min100;
  } else {
    ans = n / 2 * min(min100 * 2, min200);
  }

  cout << ans << endl;
  return 0;
}
