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

ll a, b, x;

int main() {
  cin >> a >> b >> x;

  ll aa;
  if (a % x == 0) {
    aa = a;
  } else {
    aa = a + x - a % x;
  }

  ll bb;
  if (b % x == 0) {
    bb = b;
  } else {
    bb = b - b % x;
  }

  if (bb < aa) {
    cout << 0 << endl;
    return 0;
  }

  ll diff = bb - aa;
  cout << diff / x + 1 << endl;
}
