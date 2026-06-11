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

int N, M;
int a[100], b[100], c[100], d[100];

int main() {
  cin >> N >> M;
  rep(i, 0, N) { cin >> a[i] >> b[i]; }
  rep(i, 0, M) { cin >> c[i] >> d[i]; }
  rep(i, 0, N) {
    int dist = inf;
    int ans = 0;
    rep(j, 0, M) {
      if (chmin(dist, abs(c[j] - a[i]) + abs(d[j] - b[i]))) {
        ans = j + 1;
      }
    }
    cout << ans << "\n";
  }
}
