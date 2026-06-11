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
  int N, M;
  cin >> N >> M;

  using P = pair<int, int>;
  vector<P> students(N), checkpoints(M);
  rep(i, N) { cin >> students[i].first >> students[i].second; }
  rep(i, M) { cin >> checkpoints[i].first >> checkpoints[i].second; }

  rep(i, N) {
    int x, y;
    tie(x, y) = students[i];
    P result = P(1'000'000'000, 0);
    rep(j, M) {
      int z, w;
      tie(z, w) = checkpoints[j];
      result = min(result, P(abs(x - z) + abs(y - w), j));
    }
    cout << result.second + 1 << "\n";
  }
  return 0;
}