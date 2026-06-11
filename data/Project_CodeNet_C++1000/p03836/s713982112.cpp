#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
//#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vl = vector<ll>;
using vi = vector<int>;
using Graph = vector<vi>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(15); //"for float-base
  // problem"
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  int R = tx - sx, U = ty - sy;
  REP(i, U) cout << 'U';
  REP(i, R) cout << 'R';
  REP(i, U) cout << 'D';
  REP(i, R) cout << 'L';
  cout << 'L';
  REP(i, U + 1) cout << 'U';
  REP(i, R + 1) cout << 'R';
  cout << 'D' << 'R';
  REP(i, U + 1) cout << 'D';
  REP(i, R + 1) cout << 'L';
  cout << 'U' << endl;
}