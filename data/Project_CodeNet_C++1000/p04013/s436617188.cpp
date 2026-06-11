#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr int XMAX = 2501;
int main() {
  int n, a;
  cin >> n >> a;
  vector<int> x(n);
  rep(i,n) cin >> x[i];
  vector<vector<ll>> dp(n + 1, vector<ll>(XMAX, 0));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = n; j >= 0; j--) {
      for (int k = XMAX - 1; k >= 0; k--) {
        if (j != n && x[i] + k < XMAX) dp[j + 1][k + x[i]] += dp[j][k];
      }
    }
  }
  ll res = 0;
  for (int i = 1; i <= n; i++) res += dp[i][i * a];
  cout << res << endl;
  return 0;
} 