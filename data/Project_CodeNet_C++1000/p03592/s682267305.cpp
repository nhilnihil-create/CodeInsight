#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j) {
      int now = m * i;
      now += j * (n - 2 * i);
      if (now == k) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  cout << "No" << endl;
  return 0;
}