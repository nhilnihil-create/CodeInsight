#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  if (a == b && b == c && a % 2 == 0) {
    cout << "-1" << endl;
    return 0;
  } else if (a == b && b == c && a % 2 == 1) {
    cout << "0" << endl;
    return 0;
  } else {
    int ans = 0;
    while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
      int d, e, f;
      d = (b + c) / 2;
      e = (c + a) / 2;
      f = (a + b) / 2;
      a = d;
      b = e;
      c = f;
      ans++;
    }
    cout << ans << endl;
  }
}