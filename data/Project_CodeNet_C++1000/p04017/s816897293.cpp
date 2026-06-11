#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
const ll INF = (1ll << 60);

int main() {
  ll N;
  cin >> N;

  vi x(N);
  for (ll i = 0; i < N; i++) {
    cin >> x[i];
  }

  ll L;
  cin >> L;

  vvi dp(N, vi(20, -1));

  for (ll i = 0; i < N; i++) {
    dp[i][0] =
        distance(x.begin(), upper_bound(x.begin(), x.end(), x[i] + L)) - 1;
  }

  for (ll i = 1; i < 20; i++) {
    for (ll j = N - 1; j >= 0; j--) {
      dp[j][i] = dp[dp[j][i - 1]][i - 1];
    }
  }

  ll Q;
  cin >> Q;
  for (ll i = 0; i < Q; i++) {
    ll a, b;
    cin >> a >> b;

    a -= 1;
    b -= 1;

    if (a > b)
      swap(a, b);

    ll cnt = 0;
    while (true) {
      ll j =
          distance(dp[a].begin(), lower_bound(dp[a].begin(), dp[a].end(), b));
      if (j == 0) {
        cnt += 1;
        break;
      }
      a = dp[a][j - 1];
      cnt += 1ll << (j - 1);
    }

    cout << cnt << endl;
  }
}