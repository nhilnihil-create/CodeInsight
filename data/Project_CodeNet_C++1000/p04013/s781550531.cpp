#include <bits/stdc++.h>
       
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  int N, A;
  cin >> N >> A;
  vector<int> x(N);
  for (int i = 0; i < (int)N; ++i) cin >> x[i];

  vector<vector<ll>> dp(N + 1, vector<ll>(A * N + 1, 0));
  dp[0][0] = 1;
  for (int i = 0; i < (int)N; ++i) for (int j = N; j >= 0; --j) for (int k = A * N; k >= 0; --k) {
    if (j + 1 <= N && k + x[i] <= A * N) dp[j + 1][k + x[i]] += dp[j][k];
  }

  ll ans = 0;
  for (int n = 1; n <= N; ++n) ans += dp[n][n * A];
  cout << ans << endl;
  return 0;
}
