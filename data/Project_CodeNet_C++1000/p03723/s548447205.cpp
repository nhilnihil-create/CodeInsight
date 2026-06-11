#include <bits/stdc++.h>
using namespace std;

int main() {
  long a, b, c;

  cin >> a >> b >> c;

  long d = a, e = b, f = c;

  if (a % 2 || b % 2 || c % 2) {
    cout << 0;
    return 0;
  }

  long ans = 0;

  while (1) {
    ans++;
    long atmp = a, btmp = b, ctmp = c;
    a = btmp / 2 + ctmp / 2;
    b = atmp / 2 + ctmp / 2;
    c = atmp / 2 + btmp / 2;
    if (a % 2 || b % 2 || c % 2) {
      cout << ans;
      return 0;
    } else if (a == d && b == e && c == f) {
      cout << -1;
      return 0;
    }
  }

  return 0;
}