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
  vector<int> var(3);
  rep(i, 3) { cin >> var[i]; }
  sort(var.begin(), var.end());

  int d = var[2] - var[0];
  if (d == 0) {
    cout << (var[0] % 2 == 0 ? -1 : 0) << endl;
  } else {
    int cnt = bitset<32>((d & -d) - 1).count() + 1;
    rep(i, cnt) {
      if (var[0] % 2 == 1 || var[1] % 2 == 1 || var[2] % 2 == 1) {
        cout << i << endl;
        break;
      }
      vector<int> tmp = {(var[0] + var[1]) / 2, (var[1] + var[2]) / 2,
                         (var[2] + var[0]) / 2};
      var = tmp;
    }
  }
  return 0;
}