#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dump.hpp"
#else
#define dump(...)
#define dumpv(...)
#endif

#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

void solve() {
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  if (H % h == 0 && W % w == 0) {
    cout << "No" << endl;
    return;
  }
  if (H % h != 0) {
    vector<vector<int>> m(H, vector<int>(W, -H));
    for (int y = 0; y < H; y += h) {
      rep(x, W) m[y][x] = H * (h - 1) - 1;
    }
    cout << "Yes" << endl;
    rep(y, H) {
      rep(x, W) cout << m[y][x] << " ";
      cout << endl;
    }
  } else {
    vector<vector<int>> m(H, vector<int>(W, -W));
    for (int x = 0; x < W; x += w) {
      rep(y, H) m[y][x] = W * (w - 1) - 1;
    }
    cout << "Yes" << endl;
    rep(y, H) {
      rep(x, W) cout << m[y][x] << " ";
      cout << endl;
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  // freopen("temp.1", "r", stdin);
  solve();
  return 0;
}