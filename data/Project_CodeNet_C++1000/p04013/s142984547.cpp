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

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------

// i枚目まで見てj枚選んでいてその合計がkである選び方の数
ll dp[60][60][2501];
ll N, A;
ll x[100];

int main() {
  cin >> N >> A;
  rep(i, 0, N) { cin >> x[i]; }

  dp[0][0][0] = 1;
  repe(i, 1, N) {
    repe(j, 0, N) {
      repe(k, 0, 2500) {
        if (j == 0) {
          dp[i][j][k] = dp[i - 1][j][k];
        } else {
          if (k >= x[i - 1]) {
            dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k - x[i - 1]];
          } else {
            dp[i][j][k] = dp[i - 1][j][k];
          }
        }
      }
    }
  }

  ll ans = 0;
  repe(j, 1, N) { ans += dp[N][j][A * j]; }
  cout << ans;
}
