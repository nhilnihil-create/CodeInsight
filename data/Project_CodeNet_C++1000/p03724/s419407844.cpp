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

  vector<int> p(N, 0);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    p[a]++;
    p[b]++;
  }

  int cnt = 0;
  rep(i, N) { cnt += p[i] % 2; }

  cout << (cnt <= 1 ? "YES" : "NO") << endl;
  return 0;
}