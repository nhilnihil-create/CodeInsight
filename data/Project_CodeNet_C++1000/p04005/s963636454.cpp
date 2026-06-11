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

int main() {
  ll a[3];
  rep(i, 0, 3) cin >> a[i];
  if (a[0] % 2 == 0 || a[1] % 2 == 0 || a[2] % 2 == 0)
    cout << 0 << endl;
  else {
    sort(a, a + 3);
    cout << a[0] * a[1] << endl;
  }
  return 0;
}