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

int A, B, C, D, E, F;
set<ll> wtmp, water, stmp, sugar;

int main() {
  cin >> A >> B >> C >> D >> E >> F;
  for (ll i = 0; i <= 30; ++i) {
    for (ll j = 0; j <= 30; ++j) {
      wtmp.insert(100 * i * A + 100 * j * B);
    }
  }
  for (auto e : wtmp) {
    if (e <= F) {
      water.insert(e);
    }
  }

  for (ll i = 0; i <= 3000; ++i) {
    for (ll j = 0; j <= 3000; ++j) {
      stmp.insert(i * C + j * D);
    }
  }

  for (auto e : stmp) {
    if (e <= F) {
      sugar.insert(e);
    }
  }

  double maxc = -1;
  ll ansf = 0, anss = 0;
  for (auto w : water) {
    for (auto s : sugar) {
      if (w + s > F) continue;
      if (s > w / 100 * E) continue;

      if (chmax(maxc, double(100 * s) / double(w + s))) {
        ansf = w + s;
        anss = s;
      }
    }
  }

  cout << ansf << " " << anss << endl;
}
