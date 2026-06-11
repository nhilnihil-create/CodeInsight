#include <iostream>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;
ll fact(int n) {
  ll ret{1};
  for (int i = 1; i <= n; ++i) ret = ret * i % MOD;
  return ret;
}
int main() {
  ll N, M, ans{};
  cin >> N >> M;
  if (abs(M - N) < 2) {
    ans = fact(M) % MOD * fact(N) % MOD;
    if (M == N) ans = 2 * ans % MOD;
  }
  cout << ans << endl;
}
