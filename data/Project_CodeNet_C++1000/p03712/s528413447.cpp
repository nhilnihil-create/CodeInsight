#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> f(h+2, vector<char>(w+2, '#'));
  rep(i,h) rep(j,w) cin >> f[i+1][j+1];

  rep(i,h+2) {
    rep(j,w+2) cout << f[i][j];
    cout << endl;
  }
  return 0;
}