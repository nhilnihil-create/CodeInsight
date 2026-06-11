#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  bool ok = false;

  for (int row = 0; row <= n; row++) {
    for (int column = 0; column < m; column++) {
      int black = row * m + column * n - row * column * 2;
      if (black == k) ok = true;
    }
  }

  if (ok)
    puts("Yes");
  else
    puts("No");

  return 0;
}
