#include <bits/stdc++.h>
using namespace std;

int main() {
  long q, h, s, d, n;
  long ans = 0;

  cin >> q >> h >> s >> d >> n;

  if (q * 8 > d && h * 4 > d && s * 2 > d) {
    ans += n / 2 * d;
    n %= 2;
  }
  if (q * 4 > s && h * 2 > s) {
    ans += n / 1 * s;
    n = 0;
  }
  if (q * 2 > h) {
    ans += n * 2 * h;
    n = 0;
  }
  cout << ans + n * 4 * q;

  return 0;
}