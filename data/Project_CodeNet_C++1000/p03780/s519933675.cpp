#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N, K;
  cin >> N >> K;
  vector<ll> a(N);
  for (ll i = 0; i < N; ++i) {
    cin >> a.at(i);
  }
  sort(a.begin(), a.end());
  vector<vector<ll>> dp(N + 1, vector<ll>(K, 0));
  dp.at(0).at(0) = 1;
  for (ll i = 0; i < N; ++i) {
    ll now = a.at(i);
    for (ll j = 0; j < K; ++j) {
      dp.at(i + 1).at(j) += dp.at(i).at(j);
      if (now + j < K) {
        dp.at(i + 1).at(j + now) += dp.at(i).at(j);
      }
    }
  }
  ll ans = N;
  for (ll i = 0; i < N; ++i) {
    vector<ll> last = dp.at(N);
    for (ll j = 0; j < K; ++j) {
      if (j + a.at(i) < K) {
        last.at(j + a.at(i)) -= last.at(j);
      }
      if ((j >= K - a.at(i)) && (last.at(j) != 0)) {
        ans -= 1;
        break;
      }
    }
  }
  cout << ans << "\n";
  // for (ll i = 0; i <= N; ++i) {
  //   for (ll j = 0; j < K; ++j) {
  //     cout << dp.at(i).at(j) << " ";
  //   }
  //   cout << "\n";
  // }
}
