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

int H, W;
int N;
int a[10101];
int ans[110][110];

int main() {
  cin >> H >> W;
  cin >> N;
  rep(i, 0, N) { cin >> a[i]; }

  int cnt = 0;
  for (int i = 0; i < H; ++i) {
    if (i % 2 == 0) {
      for (int j = 0; j < W; ++j) {
        if (a[cnt] == 0) {
          ++cnt;
        }
        --a[cnt];

        ans[i][j] = cnt + 1;
      }
    } else {
      for (int j = W - 1; j >= 0; --j) {
        if (a[cnt] == 0) {
          ++cnt;
        }
        --a[cnt];

        ans[i][j] = cnt + 1;
      }
    }
  }

  rep(i, 0, H) {
    rep(j, 0, W) { cout << ans[i][j] << " "; }
    cout << "\n";
  }
}
