#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> c(h);
  rep(i, h) cin >> c[i];
  rep(i, 2 * h) cout << c[i / 2] << endl;
  return 0;
}

