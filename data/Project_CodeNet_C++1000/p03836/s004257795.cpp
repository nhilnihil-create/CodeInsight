
#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
using namespace std;

using ll = long long;
const int INF = 1001001001;
const ll LLINF = 1001001001001001001;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main()
{
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  int r = tx - sx;
  int u = ty - sy;

  rep (i, r) {
    cout << 'R';
  }

  rep (i, u) {
    cout << 'U';
  }

  rep (i, r) {
    cout << 'L';
  }

  rep (i, u) {
    cout << 'D';
  }

  cout << 'D';

  rep (i, r+1) {
    cout << 'R';
  }

  rep (i, u+1) {
    cout << 'U';
  }

  cout << 'L';
  cout << 'U';

  rep (i, r+1) {
    cout << 'L';
  }

  rep (i, u+1) {
    cout << 'D';
  }

  cout << 'R' << endl;
}
