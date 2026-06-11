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

int H, W;
string a[110];

int main() {
  cin >> H >> W;
  rep(i, 0, H) { cin >> a[i]; }

  rep(i, 0, W + 2) { cout << "#"; }
  cout << endl;
  rep(i, 0, H) {
    cout << "#";
    rep(j, 0, W) { cout << a[i][j]; }
    cout << "#\n";
  }
  rep(i, 0, W + 2) { cout << "#"; }
}
