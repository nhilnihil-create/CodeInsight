#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll a, ll b, ll h) {
  cout << (a+b)*h/2 << endl;
}

int main() {
  ll a;
  cin >> a;
  ll b;
  cin >> b;
  ll h;
  cin >> h;
  solve(a, b, h);
  return 0;
}
