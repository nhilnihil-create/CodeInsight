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

int W, H, N;

int main() {
  cin >> W >> H >> N;
  int top = H;
  int bottom = 0;
  int left = 0;
  int right = W;
  rep(i, 0, N) {
    int x, y, a;
    cin >> x >> y >> a;
    if (a == 1) {
      chmax(left, x);
    } else if (a == 2) {
      chmin(right, x);
    } else if (a == 3) {
      chmax(bottom, y);
    } else {
      chmin(top, y);
    }
  }

  // cout << top << " " << bottom << " " << left << " " << right << endl;
  cout << max(0, right - left) * max(0, top - bottom) << endl;
}
