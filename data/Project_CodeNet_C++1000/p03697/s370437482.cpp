#include <iostream>
#include <string>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i,n) for(size_t i=0, i##_len=(n); i<i##_len; ++i)


void solve(ll A, ll B) {
  int ans = A+B;
  cout << (ans < 10 ? to_string(ans) : "error") << endl;
}

int main() {
  ll A;
  cin >> A;
  ll B;
  cin >> B;
  solve(A, B);
  return 0;
}
