#include <algorithm>
#include <cmath>
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

  vector<int> a(N), b(N);
  rep(i, N) { cin >> a[i] >> b[i]; }

  int64_t result = 0;
  rrep(i, N) {
    int64_t c = a[i] + result;
    if (c % b[i] == 0) {
    } else {
      result += b[i] - c % b[i];
    }
  }
  cout << result << endl;

  return 0;
}