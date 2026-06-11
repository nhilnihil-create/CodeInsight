#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c; cin >> a >> b >> c;
  int fa = a, fb = b, fc = c;
  int res = 0;
  while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
    int ha = a / 2;
    int hb = b / 2;
    int hc = c / 2;
    a = hb + hc;
    b = ha + hc;
    c = ha + hb;
    if (a == fa && b == fb && c == fc) {
      cout << -1 << endl;
      return 0;
    }
    res++;
  }
  cout << res << endl;
}