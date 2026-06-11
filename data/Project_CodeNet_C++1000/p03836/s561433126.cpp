#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  int dx = tx - sx;
  int dy = ty - sy;
  rep(i, dx) cout << 'R';
  rep(i, dy) cout << 'U';
  rep(i, dx) cout << 'L';
  rep(i, dy+1) cout << 'D';
  rep(i, dx+1) cout << 'R';
  rep(i, dy+1) cout << 'U';
  cout << "LU";
  rep(i, dx+1) cout << 'L';
  rep(i, dy+1) cout << 'D';
  cout << 'R' << endl;
  return 0;
}