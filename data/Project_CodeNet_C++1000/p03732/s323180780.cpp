#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, W;
  cin >> N >> W;
  vector<int> w(N), v(N);
  for (int i = 0; i < N; i++)
    cin >> w[i] >> v[i];
  map<int, int> dp;
  dp[0] = 0;
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    auto tmp = dp;
    for (auto it : tmp) {
      cnt++;
      if (it.first + w[i] <= W)
        dp[it.first + w[i]] = max(dp[it.first + w[i]], it.second + v[i]);
    }
  }
  int res = 0;
  for (auto it : dp)
    res = max(res, it.second);
  cout << res << '\n';
  return 0;
}
