#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  int W, H, N;
  cin >> W >> H >> N;
  vector<vector<int>> square(H, vector<int>(W, 0));
  REP(i, N) {
    int x, y, a;
    cin >> x >> y >> a;
    if (a == 1) {
      REP(i, H) REP(j, x) { square[i][j] = 1; }
    } else if (a == 2) {
      REP(i, H) for (int j = x; j < W; j++) { square[i][j] = 1; }
    } else if (a == 3) {
      REP(i, y) REP(j, W) { square[i][j] = 1; }
    } else {
      for (int i = y; i < H; i++) REP(j, W) {
          square[i][j] = 1;
        }
    }
  }
  ll ans = 0;
  REP(i, H) REP(j, W) {
    if (square[i][j] == 0) ans++;
  }
  cout << ans << endl;
}