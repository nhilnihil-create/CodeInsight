#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

ll solve(vector<ll> a, int b) {
  ll s = 0;
  ll ans = 0;
  rep(i, 0, a.size()) {
    s += a[i];
    if (i % 2 == b) {
      if (s >= 0) {
        ans += s + 1;
        s = -1;
      }
    } else {
      if (s <= 0) {
        ans += abs(s) + 1;
        s = 1;
      }
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  cout << min(solve(a, 0), solve(a, 1)) << endl;
  return 0;
}