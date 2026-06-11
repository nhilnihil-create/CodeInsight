/**
 *    author:  tourist
 *    created: 01.01.2020 20:17:49       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n >> x;
  if (x == 1 || x == 2 * n - 1) {
    cout << "No" << '\n';
    return 0;
  }
  cout << "Yes" << '\n';
  vector<int> a(2 * n - 1);
  a[n - 1] = x;
  a[n - 2] = x - 1;
  a[n] = x + 1;
  int ptr = 0;
  for (int i = 2 * n - 1; i >= 1; i--) {
    if (abs(i - x) <= 1) {
      continue;
    }
    while (ptr >= n - 2 && ptr <= n) {
      ++ptr;
    }
    a[ptr++] = i;
  }
  for (int i = 0; i < 2 * n - 1; i++) {
    cout << a[i] << '\n';
  }
  return 0;
}
