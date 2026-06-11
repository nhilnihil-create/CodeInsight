#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  bool flag = false;
  for (int a = 0; a <= n; a++) {
    for (int b = 0; b <= m; b++) {
      if (a * (m - b) + b * (n - a) == k) flag = true;
    }
  }
  // for (int a = 0; a <= n; a++) {
  //   int b = (a * m - k) / (n - 2 * a);
  //   if (a * (m - b) + b * (n - a) == k) flag = true;
  // }
  cout << (flag ? "Yes" : "No") << endl;
  return 0;
}
