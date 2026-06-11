#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll x, ll a, ll b) {
  cout << (abs(a-x) < abs(b-x) ? "A" : "B") << endl;
}

int main() {
  ll x;
  cin >> x;
  ll a;
  cin >> a;
  ll b;
  cin >> b;
  solve(x, a, b);
  return 0;
}
