#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
ll N;
vector<ll> Dp, DpSum;
int main() {
  cin >> N;
  Dp.resize(N);
  DpSum.resize(N);
  Dp[N - 1] = DpSum[N - 1] = N;
  for (ll i = N - 2; i >= 0; --i) {
    // 1
    (Dp[i] += Dp[i + 1]) %= MOD;
    // xyyy... (x,y non-one)
    (Dp[i] += (N - 1) * (N - 1)) %= MOD;
    // n1...1
    if (i <= N - 4) {
      (Dp[i] += DpSum[i + 3]) %= MOD;
      (Dp[i] += i + 2) %= MOD;
    } else {
      (Dp[i] += N - 1) %= MOD;
    }
    DpSum[i] = (DpSum[i + 1] + Dp[i]) % MOD;
  }
  cout << Dp[0] << endl;
  return 0;
}
