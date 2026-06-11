#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll x) {
  cout << (x < 1200 ? "ABC" : "ARC") << endl;
}

int main() {
  ll x;
  cin >> x;
  solve(x);
  return 0;
}
