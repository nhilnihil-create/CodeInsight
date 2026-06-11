#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
  ll x = tx-sx, y = ty-sy;
  rep(i, y) cout << 'U';
  rep(i, x) cout << 'R';
  rep(i, y) cout << 'D';
  rep(i, x) cout << 'L';
  cout << 'L';
  rep(i, y+1) cout << 'U';
  rep(i, x+1) cout << 'R';
  cout << 'D' << 'R';
  rep(i, y+1) cout << 'D';
  rep(i, x+1) cout << 'L';
  cout << 'U' << endl;
}