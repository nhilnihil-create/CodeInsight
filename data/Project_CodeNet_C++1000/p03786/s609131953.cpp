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

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main() {
  int N;
  cin >> N;

  vector<int64_t> a(N);
  rep(i, N) { cin >> a[i]; }
  sort(a.begin(), a.end());

  vector<int64_t> acc(a);
  rep(i, N - 1) { acc[i + 1] += acc[i]; }

  vector<int> b(N);
  rrep(i, N) {
    b[i] = i;
    b[i] = b[upper_bound(a.begin(), a.end(), 2 * acc[i]) - a.begin() - 1];
  }

  int result = 0;
  rep(i, N) { result += (b[i] == N - 1 ? 1 : 0); }
  cout << result << endl;
  return 0;
}