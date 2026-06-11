#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <cstdint>
#include <cmath>
#include <bitset>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

#define N_TIMES(i, n)     for ( uint64_t i = 0;     i <  n; ++i )
#define N_TIMES_REV(i, n) for (  int64_t i = n - 1; i >= 0; --i )

using namespace std;

int main()
{
  uint64_t H, W, N;
  cin >> H >> W >> N;

  vector<uint64_t> a(N);
  N_TIMES(n, N) { cin >> a[n]; }

  vector<vector<uint64_t>> c(H);
  N_TIMES(h, H) { c[h] = vector<uint64_t>(W, 0); }
  
  uint64_t x = 0, y = 0;
  N_TIMES(n, N) {
    N_TIMES(i, a[n]) {
      c[y][x] = n + 1;
      
      if (y % 2 == 0) {
        ++x;
        if (x == W) {
          ++y;
          x = W - 1;
        }
      } else {
        --x;
        if (x == -1) {
          ++y;
          x = 0;
        }
      }
    }
  }

  N_TIMES(h, H) {
    N_TIMES(w, W) {
      cout << c[h][w];
      if (w + 1 < W) { cout << ' '; }
    }
    cout << endl;
  }

  return 0;
}