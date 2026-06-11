#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

vector<int> Solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> xs(n);
  for (int i = 0; i < n; i++) {
    xs[i] = s[i] == 'x';
  }

  vector<int> ys(n + 2);
  for (int y0 = 0; y0 < 2; y0++) {
    for (int y1 = 0; y1 < 2; y1++) {
      ys[0] = y0;
      ys[1] = y1;
      for (int i = 2; i < n + 2; i++) {
        ys[i] = xs[(i - 1) % n] ^ ys[i - 2] ^ ys[i - 1];
      }

      if (ys[0] == ys[n] && ys[1] == ys[n + 1]) {
        ys.pop_back();
        ys.pop_back();
        return ys;
      }
    }
  }
  return vector<int>();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> ans = Solve();
  if (ans.empty()) {
    cout << -1 << endl;
  } else {
    for (int v : ans) {
      cout << "SW"[v];
    }
    cout << endl;
  }
}