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
  int N, M, K;
  cin >> N >> M >> K;

  irep(i, N) {
    int R = K - M * i;
    int S = N - 2 * i;
    if (S == 0) {
      if (R == 0) {
        cout << "Yes" << endl;
        return 0;
      }
    } else if (R % S == 0) {
      const int j = R / S;
      if (j >= 0 && j <= M) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}