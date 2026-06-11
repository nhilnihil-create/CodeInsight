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

// -------------------------------------------------------

int N;
bool dp[10101];

int main() {
  cin >> N;
  dp[0] = true;
  rep(i, 0, N) {
    int s;
    cin >> s;
    for (int j = 10000; j >= 0; --j) {
      if (dp[j]) {
        dp[j + s] = true;
      }
    }
  }

  for (int i = 9999; i >= 1; --i) {
    if (i % 10 == 0) continue;

    if (dp[i]) {
      cout << i;
      return 0;
    }
  }

  cout << 0;
}
