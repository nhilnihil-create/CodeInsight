#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

#define chmax(a, b) (a) = max(a, b)
#define chmin(a, b) (a) = min(a, b)

int main() {
  int W, H, N;
  cin >> W >> H >> N;

  int xl = 0, xr = W, yl = 0, yr = H;
  rep(i, N) {
    int a, x, y;
    cin >> x >> y >> a;
    switch (a) {
      case 1:
        chmax(xl, x);
        break;
      case 2:
        chmin(xr, x);
        break;
      case 3:
        chmax(yl, y);
        break;
      case 4:
        chmin(yr, y);
        break;
      default:
        break;
    }
  }
  cout << max(0, xr - xl) * max(0, yr - yl) << endl;
  cerr << xl << " " << xr << " " << yl << " " << yr << endl;
  return 0;
}