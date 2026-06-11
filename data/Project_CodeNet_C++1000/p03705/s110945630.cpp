#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;

  if (a > b) {
    cout << 0 << endl;
    return 0;
  }
  if (a != b && n == 1) {
    cout << 0 << endl;
    return 0;
  }

  ll min = b + a * (n - 1);
  ll max = a + b * (n - 1);
  ll ans = max - min + 1;

  cout << ans << endl;
}
