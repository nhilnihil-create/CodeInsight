#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

const string YES = "Possible";
const string NO = "Impossible";

void solve(ll A, ll B) {
  bool pred = A % 3 == 0 || B % 3 == 0 || (A + B) % 3 == 0;
  cout << (pred ? YES : NO) << endl;
}

int main() {
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  solve(A, B);
  return 0;
}
