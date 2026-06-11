#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = INT_MAX;
const int MOD = 1000000007;
const long long INF = LLONG_MAX;
const long long MINF = LLONG_MIN;

// -------------------------------------------------------

ll N, W;
map<ll, vector<ll>> vs;
ll csum[4][200];
ll items[4];
ll minw;

int main() {
  cin >> N >> W;
  rep(i, 0, N) {
    ll w, v;
    cin >> w >> v;
    vs[w].push_back(v);
  }

  ll cnt = 0;
  for (auto e : vs) {
    if (cnt == 0) minw = e.first;

    sort(e.second.begin(), e.second.end(), greater<ll>());
    rep(i, 0, e.second.size()) {
      csum[cnt][i + 1] = csum[cnt][i] + e.second[i];
    }
    items[cnt] = e.second.size();
    ++cnt;
    vs[e.first] = e.second;
  }

  ll ans = 0;
  for (ll i = 0; i <= items[0]; ++i) {
    for (ll j = 0; j <= items[1]; ++j) {
      for (ll k = 0; k <= items[2]; ++k) {
        ll total = minw * i + (minw + 1) * j + (minw + 2) * k;
        if (total > W) {
          continue;
        }

        ll rest = W - total;
        ll l = rest / (minw + 3);

        chmax(ans, csum[0][i] + csum[1][j] + csum[2][k] + csum[3][l]);
      }
    }
  }

  cout << ans;
}
