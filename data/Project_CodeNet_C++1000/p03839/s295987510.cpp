#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> la(n);
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> la[i];
    if (la[i] > 0) ans += la[i];
  }
  ll s1 = 0, s2 = 0;
  ll b1 = -1e17, b2 = 1e17;
  for (int i = 0; i < n; ++i) {
    if (la[i] < 0) s1 += la[i];
    else s2 += la[i];
    if (i >= k) {
      if (la[i-k] < 0) s1 -= la[i-k];
      else s2 -= la[i-k];
    }
    if (i >= k-1) {
      b1 = max(b1, s1);
      b2 = min(b2, s2);
    }
    // cout << i << " " << b1 << " " << b2 << endl;
  }
  // cout << b1 << " " << b2 << endl;
  ll b = min(-b1, b2);
  ans -= b;
  cout << ans << endl;
}