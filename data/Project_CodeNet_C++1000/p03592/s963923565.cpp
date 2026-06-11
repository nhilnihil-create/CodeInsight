#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k;

  cin >> n >> m >> k;

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      int x = i * m;
      int y = j * n;
      x = x > 0 && y > 0 ? x - (j * i) : x;
      y = y > 0 && x > 0 ? y - (i * j) : y;
      if (x + y == k) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;

  return 0;
}