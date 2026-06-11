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

ll H, W;

int main() {
  cin >> H >> W;

  ll ans = INF;
  repe(i, 1, H - 1) {
    ll p1 = i * W;

    ll rh = H - i;
    if (rh % 2 == 0 || W % 2 == 0) {
      ll p2 = rh * W / 2;
      chmin(ans, abs(p1 - p2));
    } else {
      if (rh > W) {
        ll p2 = rh / 2 * W;
        ll p3 = rh * W - p2;
        ll ma = max(p1, max(p2, p3));
        ll mi = min(p1, min(p2, p3));
        chmin(ans, ma - mi);
      } else {
        ll p2 = W / 2 * rh;
        ll p3 = rh * W - p2;
        ll ma = max(p1, max(p2, p3));
        ll mi = min(p1, min(p2, p3));
        chmin(ans, ma - mi);
      }
    }
  }

  repe(i, 1, W - 1) {
    ll p1 = i * H;

    ll rw = W - i;
    if (rw % 2 == 0 || H % 2 == 0) {
      ll p2 = rw * H / 2;
      chmin(ans, abs(p1 - p2));
    } else {
      if (rw > H) {
        ll p2 = rw / 2 * H;
        ll p3 = rw * H - p2;
        ll ma = max(p1, max(p2, p3));
        ll mi = min(p1, min(p2, p3));
        chmin(ans, ma - mi);
      } else {
        ll p2 = H / 2 * rw;
        ll p3 = rw * H - p2;
        ll ma = max(p1, max(p2, p3));
        ll mi = min(p1, min(p2, p3));
        chmin(ans, ma - mi);
      }
    }
  }

  cout << ans;
}
