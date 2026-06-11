#include <iostream>

using namespace std;

typedef long long ll;

int main () {
  ll n, x;
  cin >> n >> x;

  ll ans = n;
  ll p = x, q = n - x;
  if (p < q) swap(p, q);
  while (true) {
    if (p % q == 0) {
      ans += (2 * (p / q) - 1) * q;
      break;
    } else {
      ans += 2 * q * (p / q);
      p %= q;
      swap(p, q);
    }
  }

  cout << ans << endl;
}
