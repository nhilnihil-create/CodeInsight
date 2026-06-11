#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int64 h, w;
  int n;
  cin >> h >> w >> n;

  map<tuple<int, int>, int> m;
  for (int i = 0; i < n; i++) {
    int r, c;
    cin >> r >> c;
    r--;
    c--;
    for (int dy = -1; dy <= 1; dy++) {
      for (int dx = -1; dx <= 1; dx++) {
        int nr = r + dy;
        int nc = c + dx;
        if (nr < 1 || h - 1 <= nr) continue;
        if (nc <1  || w - 1 <= nc) continue;
        m[make_tuple(nr, nc)]++;
      }
    }
  }

  vector<int64> rs(10);
  rs[0] = (h - 2) * (w - 2);
  for (const auto& kv : m) {
    // cout << get<0>(kv.first) << " " << get<1>(kv.first) << " " << kv.second << endl;
    rs[kv.second]++;
    rs[0]--;
  }

  for (int i = 0; i <= 9; i++) {
    cout << rs[i] << endl;
  }
}