#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
  int n, m, k, ans = 0;
  cin >> n >> m >> k;
  bool ok = false;
  rep(i, n + 1) rep(j, m + 1) if (i * (m - j) + j * (n - i) == k) ok = true;

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}
