#include <algorithm>
#include <bitset>
#include <boost/rational.hpp>
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
  int K, T;
  cin >> K >> T;

  vector<int> a(T);
  rep(i, T) { cin >> a[i]; }
  sort(a.begin(), a.end());
  int s = 0;
  rep(i, T - 1) { s += a[i]; }

  cout << max(0, a.back() - 1 - s) << endl;
  return 0;
}
