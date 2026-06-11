#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int h, w, n, x, y;
  cin >> h >> w >> n;

  auto inside = [&](int x, int y) { // not on edge
    return 0 < x && x < h - 1 && 0 < y && y < w - 1;
  };

  map< pair<int,int>, int > g;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    x--; y--;
    for (int j = -1; j <= 1; j++) {
      for (int k = -1; k <= 1; k++) {
        if (inside(x + j, y + k)) {
          g[make_pair(x + j, y + k)]++;
        }
      }
    }
  }

  cout << (long long) (h - 2) * (w - 2) - g.size() << '\n';
  vector<int> num(10);
  for (auto i : g) {
    num[i.second]++;
  }
  for (int i = 1; i < 10; i++) {
    cout << num[i] << '\n';
  }
  return 0;
}