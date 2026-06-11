#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll X, ll A, ll B) {
  if (B - A <= 0) {
    cout << "delicious" << endl;
  } else if (B - A <= X) {
    cout << "safe" << endl;
  } else {
    cout << "dangerous" << endl;
  }
}

int main() {
  ll X;
  cin >> X;
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  solve(X, A, B);
  return 0;
}
