#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using lpair = pair<llong, llong>;

#define ALL(x) x.begin(), x.end()

constexpr llong mod = 1e9+7;
constexpr llong inf = mod * mod;

int main() {
  llong sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  llong disx = tx - sx;
  llong disy = ty - sy;

  cerr << disx << " " << disy << endl;

  cout << string(disx, 'R') <<
      string(disy, 'U') <<
      string(disx, 'L') <<
      string(disy, 'D') <<
      "D" <<
      string(disx + 1, 'R') <<
      string(disy + 1, 'U') <<
      "LU" <<
      string(disx + 1, 'L') <<
      string(disy + 1, 'D') <<
      "R"
  << endl;

  return 0;
}