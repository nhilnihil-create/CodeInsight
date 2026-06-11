#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  ll ans = 0;
  ll tmp = 0;
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    if (a == 0) {
      ans += tmp / 2;
      tmp = 0;
    } else {
      tmp += a;
    }
  }
  ans += tmp / 2;
  cout << ans << endl;
}