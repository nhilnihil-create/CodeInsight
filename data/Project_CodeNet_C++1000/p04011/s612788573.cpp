#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll N, ll K, ll X, ll Y) {
  cout << (K < N ? K * X + (N - K) * Y : N * X) << endl;
}

int main() {
  ll N;
  cin >> N;
  ll K;
  cin >> K;
  ll X;
  cin >> X;
  ll Y;
  cin >> Y;
  solve(N, K, X, Y);
  return 0;
}
