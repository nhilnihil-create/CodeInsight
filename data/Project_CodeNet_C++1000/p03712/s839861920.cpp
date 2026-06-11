#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using GraphI = vector<vector<int>>;
using GraphC = vector<vector<char>>;
using pint = pair<int, int>;

int main() {
  int H, W;
  cin >> H >> W;
  GraphC g(H + 2, vector<char>(W + 2, '#'));
  repe(y, 1, H) repe(x, 1, W) cin >> g[y][x];

  rep(y, 0, H + 2) {
    rep(x, 0, W + 2) cout << g[y][x];
    cout << endl;
  }

  return 0;
}
