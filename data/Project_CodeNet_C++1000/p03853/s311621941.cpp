#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int INF = 1001001001;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> g(H, vector<char>(W));
  rep(y, 0, H) rep(x, 0, W) cin >> g[y][x];

  rep(y, 0, H) {
    rep(i, 0, 2) {
      rep(x, 0, W) cout << g[y][x];
      cout << endl;
    }
  }

  return 0;
}
