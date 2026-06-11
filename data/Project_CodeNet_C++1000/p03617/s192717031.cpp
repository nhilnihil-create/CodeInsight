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
  int64_t Q, H, S, D, N;
  cin >> Q >> H >> S >> D >> N;

  H = min(H, 2 * Q);
  S = min(S, 2 * H);
  D = min(D, 2 * S);

  cout << N / 2 * D + N % 2 * S << endl;
  return 0;
}