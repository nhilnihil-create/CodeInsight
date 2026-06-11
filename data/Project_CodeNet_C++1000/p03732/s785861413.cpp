#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int N, W;
  cin >> N >> W;
  vector<pair<int, int>> items(N);
  rep(i, N)
  {
    cin >> items[i].first >> items[i].second;
  }
  ll w0 = items[0].first;
  vector<vector<vector<ll>>> dp(N + 1, vector<vector<ll>>(N + 1, vector<ll>(3 * N + 1, -1)));
  dp[0][0][0] = 0;

  rep(i, N) rep(cnt_i, N) rep(num_i, N * 3 + 1)
  {
    if (dp[i][cnt_i][num_i] != -1)
    {
      ll w = items[i].first;
      ll v = items[i].second;
      dp[i + 1][cnt_i][num_i] = max(dp[i + 1][cnt_i][num_i], dp[i][cnt_i][num_i]);
      dp[i + 1][cnt_i + 1][num_i + w - w0] = max(dp[i + 1][cnt_i + 1][num_i + w - w0], dp[i][cnt_i][num_i] + v);
    }
  }

  ll ans = 0;
  rep(cnt_i, N + 1) rep(num_i, N * 3 + 1)
  {
    if (w0 * cnt_i + num_i <= W)
      ans = max(ans, dp[N][cnt_i][num_i]);
  }
  cout << ans << endl;
  return 0;
}