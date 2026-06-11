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
  rep(i, N) {
    cin >> a[i];
    a[i]--;
  }

  int result = 0;
  rep(i, N) {
    if (i == a[a[i]]) {
      result++;
    }
  }
  cout << result / 2 << endl;
  return 0;
}