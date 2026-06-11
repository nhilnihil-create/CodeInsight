#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
#define accum(x) accumulate((x).begin(), (x).end(), 0)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int COLORS = 8;

int main() {
  int n, a;
  cin >> n;
  vector<int> v(COLORS + 1);
  rep(i, 0, n) {
    cin >> a;
    if (1 <= a && a <= 399)
      v[0] = 1;
    else if (400 <= a && a <= 799)
      v[1] = 1;
    else if (800 <= a && a <= 1199)
      v[2] = 1;
    else if (1200 <= a && a <= 1599)
      v[3] = 1;
    else if (1600 <= a && a <= 1999)
      v[4] = 1;
    else if (2000 <= a && a <= 2399)
      v[5] = 1;
    else if (2400 <= a && a <= 2799)
      v[6] = 1;
    else if (2800 <= a && a <= 3199)
      v[7] = 1;
    else if (3200 <= a)
      v[8]++;
  }

  int ma = accum(v);
  int mi = 0;
  rep(i, 0, COLORS) mi += v[i];
  if (v[8] == n)
    cout << 1 << " " << ma << endl;
  else
    cout << mi << " " << ma << endl;
  return 0;
}
