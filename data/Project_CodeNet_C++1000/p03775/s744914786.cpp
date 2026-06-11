#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  ll ans = 1e3;
  for (ll a = 1; a <= sqrt(n)+1; ++a) {
    ll b = n / a;
    if (a * b != n)
      continue;
    ll tmp = max(a, b);
    ll cnt = 0;
    while (tmp) {
      ++cnt;
      tmp /= 10;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
}
