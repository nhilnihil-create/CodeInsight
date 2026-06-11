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
int dp[1000][1000];
int N, Ma, Mb;
int a[100], b[100], c[100];

int main() {
  cin >> N >> Ma >> Mb;
  rep(i, 0, N) { cin >> a[i] >> b[i] >> c[i]; }

  rep(i, 0, 1000) {
    rep(j, 0, 1000) { dp[i][j] = 100000; }
  }
  dp[0][0] = 0;

  rep(i, 0, N) {
    int ca = a[i];
    int cb = b[i];
    int cc = c[i];
    for (int j = 400; j >= 0; --j) {
      for (int k = 400; k >= 0; --k) {
        chmin(dp[j + ca][k + cb], dp[j][k] + cc);
      }
    }
  }

  int ans = 100000;
  repe(i, 1, 400) {
    int cma = i * Ma;
    int cmb = i * Mb;
    if (cma > 400 || cmb > 400) break;

    chmin(ans, dp[cma][cmb]);
  }
  if (ans >= 100000) {
    cout << -1;
    return 0;
  }

  cout << ans;
}
