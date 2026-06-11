#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

const string YES = "Yes";
const string NO = "No";

void solve(ll a, ll b, ll c) {
  bool pred = a+b+c == 2*max({a,b,c});
  cout << (pred ? YES : NO) << endl;
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
