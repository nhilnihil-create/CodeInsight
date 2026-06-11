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

ll N;
string S[2];
int pre;

int main() {
  cin >> N;
  cin >> S[0];
  cin >> S[1];

  ll ans = 1;
  for (int i = 0; i < N; ++i) {
    if (S[0][i] == S[1][i]) {
      if (pre == 0) {
        ans *= 3;
        ans %= MOD;
      } else if (pre == 1) {
        ans *= 2;
        ans %= MOD;
      } else {
        // none
      }

      pre = 1;
    } else {
      if (pre == 0) {
        ans *= 6;
        ans %= MOD;
      } else if (pre == 1) {
        ans *= 2;
        ans %= MOD;
      } else {
        ans *= 3;
        ans %= MOD;
      }

      pre = 2;
      ++i;
    }
  }

  cout << ans;
}
