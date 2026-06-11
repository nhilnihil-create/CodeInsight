#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll X, ll t) {
  cout << max(0ll, X-t) << endl;
}

int main() {
  ll X;
  cin >> X;
  ll t;
  cin >> t;
  solve(X, t);
  return 0;
}
