#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> a;
vector<vector<long long>> dp;

int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  dp.assign(n, vector<long long>(2, 1));
  for (int i = 1; i < n; ++i) {
    dp[i][0] = min(dp[i - 1][0] + (a[i] > a[i - 1]), dp[i - 1][1] + 1);
    dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][1] + (a[i] < a[i - 1]));
  }
  cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
  return 0;
}
