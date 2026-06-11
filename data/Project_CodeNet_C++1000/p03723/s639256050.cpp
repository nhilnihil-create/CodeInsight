#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ta = a;
  int tb = b;
  int tc = c;
  int tot = a + b + c;
  int ans = 0;
  while (true) {
    if (a % 2 != 0 || b % 2 != 0 || c % 2 != 0) {
      break;
    }
    a = (tot - a) / 2;
    b = (tot - b) / 2;
    c = (tot - c) / 2;
    ans++;
    if (a == ta && b == tb && c == tc) {
      ans = -1;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
