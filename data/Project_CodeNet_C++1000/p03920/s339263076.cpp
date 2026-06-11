#include <bits/stdc++.h>
using namespace std;
signed main() {
  int n, m, l;
  cin >> n;
  int x = 1;
  while (true) {
    if (x * (x + 1) >= 2 * n) break;
    x++;
  }
  m = x * (x + 1) / 2;
  l = m - n;
  for (int j = 1; j <= x; j++) {
    if (j == l) continue;
    cout << j << endl;
  }
  //   cout << endl;
  //   cout << l << endl;
}