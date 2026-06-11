#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll a, ll b, ll c) {
  cout << a+b+c-max({a,b,c}) << endl;
}

int main() {
  ll a;
  cin >> a;
  ll b;
  cin >> b;
  ll c;
  cin >> c;
  solve(a, b, c);
  return 0;
}
