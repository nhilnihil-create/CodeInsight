#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

bool ok[10];
int main() {
  int n, k;
  cin >> n >> k;
  rep(i, 0, k) {
    int d;
    cin >> d;
    ok[d] = true;
  }

  auto check = [&](int m) {
    bool res = true;
    while (m > 0) {
      if (ok[m % 10]) res = false;
      m /= 10;
    }
    return res;
  };

  int ans = n;
  while (true) {
    if (check(ans)) {
      cout << ans << endl;
      return 0;
    }
    ++ans;
  }

  return 0;
}