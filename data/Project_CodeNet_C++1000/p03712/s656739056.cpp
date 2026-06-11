#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> p(h+2, vector<char>(w+2, '#'));
  for (int i = 1; i <= h; ++i) for (int j = 1; j <= w; ++j) cin >> p[i][j];
  rep(i, h+2) {
    rep(j, w+2) cout << p[i][j];
    cout << endl;
  }
  return 0;
}