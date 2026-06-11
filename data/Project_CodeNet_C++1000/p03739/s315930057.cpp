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

ll n;
ll csum[101010];

int main() {
  cin >> n;
  repe(i, 1, n) {
    ll a;
    cin >> a;
    csum[i] = csum[i - 1] + a;
  }

  ll ans = 0;
  ll inc = 0;
  repe(i, 1, n) {
    ll cur = csum[i] + inc;
    if (i % 2 == 1) {
      if (cur <= 0) {
        ans += 1 - cur;
        inc += 1 - cur;
      }
    } else {
      if (cur >= 0) {
        ans += cur + 1;
        inc -= cur + 1;
      }
    }
  }

  ll ans2 = 0;
  ll inc2 = 0;
  repe(i, 1, n) {
    ll cur = csum[i] + inc2;
    if (i % 2 == 1) {
      if (cur >= 0) {
        ans2 += cur + 1;
        inc2 -= cur + 1;
      }
    } else {
      if (cur <= 0) {
        ans2 += 1 - cur;
        inc2 += 1 - cur;
      }
    }
  }

  cout << min(ans, ans2);
}
