#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N, A, B;
  cin >> N >> A >> B;

  vector<int> X(N);
  rep(i, N) cin >> X[i];

  vector<ll> dp(N);
  dp[0] = 0;
  for (int i = 1; i < N; ++i) {
    ll a = (X[i] - X[i - 1]) * A;
    ll b = B;
    dp[i] = min(a, b) + dp[i - 1];
  }

  cout << dp.back() << endl;
}