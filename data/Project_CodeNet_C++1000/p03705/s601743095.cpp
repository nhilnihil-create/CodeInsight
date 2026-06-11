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
  int N, A, B;
  cin >> N >> A >> B;

  if (A > B) {
    cout << 0 << endl;
  } else if (N == 1) {
    cout << (A == B ? 1 : 0) << endl;
  } else {
    int64_t L = (int64_t)A * (N - 1) + B;
    int64_t R = (int64_t)B * (N - 1) + A;

    cout << R - L + 1 << endl;
  }

  return 0;
}