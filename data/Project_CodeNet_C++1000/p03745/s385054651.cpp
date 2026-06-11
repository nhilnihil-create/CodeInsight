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

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) { cin >> a[i]; }

  int cnt = 0;
  int b = a[0];
  int state = 0;
  rep(i, N) {
    if (b < a[i]) {
      if (state < 0) {
        cnt++;
        state = 0;
      } else {
        state = 1;
      }
    } else if (b > a[i]) {
      if (state > 0) {
        cnt++;
        state = 0;
      } else {
        state = -1;
      }
    }
    b = a[i];
  }
  cout << cnt + 1 << endl;
  return 0;
}