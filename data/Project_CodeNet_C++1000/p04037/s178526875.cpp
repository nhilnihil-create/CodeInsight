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
  int N;
  cin >> N;

  vector<int> a(N);
  rep(i, N) { cin >> a[i]; }
  sort(a.begin(), a.end(), greater<int>());

  a.push_back(0);

  int i = 0;
  while (i + 1 < N && i + 1 < a[i + 1]) {
    i++;
  }

  int j = lower_bound(a.begin(), a.end(), i, greater<int>()) - a.begin();
  cout << ((a[i] - i) % 2 == 1 && (j - i) % 2 == 1 ? "Second" : "First")
       << endl;

  return 0;
}