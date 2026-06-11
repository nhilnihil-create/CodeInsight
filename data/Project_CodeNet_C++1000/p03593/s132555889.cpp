#include <bits/stdc++.h>
using namespace std;

bool f(int n, int m, vector<int>& v) {
  while (n > 0) {
    if (v.back() < m) {
      return false;
    }
    if (v.back() >= m) {
      v.back() -= m;
      n -= m;
    }
    sort(v.begin(), v.end());
  }
  return true;
}

int main() {
  int h, w;
  cin >> h >> w;

  vector<int> alpha(26);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      char c;
      cin >> c;
      alpha[c - 'a'] += 1;
    }
  }
  sort(alpha.begin(), alpha.end());

  int x = h % 2 == 0 ? 0 : w - 1;
  int y = w % 2 == 0 ? 0 : h - 1;
  int z = h * w - (h % 2 == 0 ? 0 : w) - (w % 2 == 0 ? 0 : h);

  bool ok = f(z, 4, alpha) && f(y, 2, alpha) && f(x, 2, alpha);
  if (ok) {
    cout << "Yes" << endl;
    return 0;
  }
  cout << "No" << endl;
}