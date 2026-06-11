#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, k;
  cin >> n >> k;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a.at(i);
  
  sort(a.begin(), a.end());
  
  int l = -1, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= k; j++) {
        if (i == mid) {
          dp[i + 1][j] = dp[i][j];
        }
        else if (dp[i][j]) {
          dp[i + 1][j] = true;
          if (j + a.at(i) <= k) dp[i + 1][j + a.at(i)] = true;
        }
      }
    }
    bool need = false;
    for (int j = max(k - a.at(mid), 0); j < k; j++) {
      if (dp[n][j]) need = true;
    }
    if (need) r = mid;
    else l = mid;
  }
  
  cout << l + 1 << '\n';
}