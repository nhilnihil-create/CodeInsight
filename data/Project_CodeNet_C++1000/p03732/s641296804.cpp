#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
#define sz(x) ((int)(x).size())
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int N;
  ll W;
  cin >> N >> W;
  vector<ll> w(N), v(N);
  rep(i, N) cin >> w[i] >> v[i];

  vector<vector<vector<ll>>> value(
      N + 1, vector<vector<ll>>(3 * N + 1, vector<ll>(N + 1)));
  rep(n, N) {
    rep(j, 3 * N + 1) {
      rep(k, N + 1) {
        ll V = v[n];
        ll res = w[n] - w[0];
        // Not use
        chmax(value[n + 1][j][k], value[n][j][k]);
        // Use
        if (k + 1 <= N && j + res <= 3 * N)
          chmax(value[n + 1][j + res][k + 1], value[n][j][k] + V);
      }
    }
  }

  ll ans = 0;
  rep(j, 3 * N + 1) {
    rep(k, N + 1) {
      ll temp = j + w[0] * k;
      if (temp <= W)
        chmax(ans, value[N][j][k]);
    }
  }

  cout << ans << endl;
}