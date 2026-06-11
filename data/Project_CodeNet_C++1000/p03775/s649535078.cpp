#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  int dig_min = (1U << 15) - 1;
  cin >> n;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ll mx = max(i, n / i);
      int dig = (int)to_string(mx).size();
      dig_min = min(dig_min, dig);
    }
  }

  cout << dig_min << endl;
  return 0;
}
