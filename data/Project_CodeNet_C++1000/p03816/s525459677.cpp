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
const long long MINF = LLONG_MIN;

// -------------------------------------------------------

map<int, int> all;
int dupcnt, nodupcnt, dupvar;

int N;

int main() {
  cin >> N;
  rep(i, 0, N) {
    int a;
    cin >> a;
    ++all[a];
  }

  for (auto e : all) {
    if (e.second == 1) {
      ++nodupcnt;
    } else {
      dupcnt += e.second - 1;
      ++dupvar;
    }
  }

  if (dupcnt % 2 == 0) {
    cout << nodupcnt + dupvar;
  } else {
    cout << nodupcnt + dupvar - 1;
  }
}
