#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  ll q, h, s, d, n;
  cin >> q >> h >> s >> d >> n;
  ll one = min(4 * q, min(2 * h, s));
  ll two = min(2 * one, d);
  ll ans = n / 2 * two;
  if (n % 2 != 0) {
    ans += one;
  }
  cout << ans << endl;
  return 0;
}