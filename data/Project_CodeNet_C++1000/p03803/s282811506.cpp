#include <iostream>
#include <string>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll A, ll B) {
  A = (A+11)%13;
  B = (B+11)%13;
  string ans = A > B ? "Alice" : A < B ? "Bob" : "Draw";
  cout << ans << endl;
}

int main() {
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  solve(A, B);
  return 0;
}
