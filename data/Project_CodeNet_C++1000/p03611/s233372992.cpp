#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> dp(100001, 0);
  rep(i, n) {
    ++dp[a[i]];
    if (a[i] > 0) ++dp[a[i] - 1];
    ++dp[a[i] + 1];
  }
  int ans = 0;
  rep(x, 100001) ans = max(ans, dp[x]);
  cout << ans << endl;
  return 0;
}