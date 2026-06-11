#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll A, string op, ll B) {
  cout << A + B * (op == "+" ? 1 : -1) << endl;
}

int main() {
  ll A;
  cin >> A;
  string op;
  cin >> op;
  ll B;
  cin >> B;
  solve(A, op, B);
  return 0;
}
