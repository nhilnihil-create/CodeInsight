#include <algorithm>
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
  vector<string> a(N), b(M);
  rep(i, N) { cin >> a[i]; }
  rep(i, M) { cin >> b[i]; }

  irep(i, N - M) irep(j, N - M) {
    bool c = true;

    rep(k, M) rep(l, M) { c = c && (a[i + k][j + l] == b[k][l]); }

    if (c) {
      cout << "Yes\n";
      return 0;
    }
  }

  cout << "No\n";

  return 0;
}