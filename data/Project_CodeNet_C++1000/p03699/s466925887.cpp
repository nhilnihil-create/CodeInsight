#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> s(n);
  rep(i, n) cin >> s[i];

  vector<int> dp(10001, 0);
  dp[0] = 1;

  rep(i, n) for (int j = 10000; j >= 0; --j) {
    if (dp[j] == 1) continue;
    if (j - s[i] >= 0) dp[j] = dp[j - s[i]];
  }

  int ans = 0;
  for (int j = 10000; j >= 0; --j) {
    if (dp[j] == 1 && j % 10 != 0) {
      ans = j;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}