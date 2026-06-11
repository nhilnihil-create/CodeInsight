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

int x, y;

int main() {
  cin >> x >> y;
  if (x == 2) {
    if (y == 2) {
      cout << "Yes";
    } else {
      cout << "No";
    }
  } else if (x == 4 || x == 6 || x == 9 || x == 11) {
    if (y == 4 || y == 6 || y == 9 || y == 11) {
      cout << "Yes";
    } else {
      cout << "No";
    }
  } else {
    if (y == 1 || y == 3 || y == 5 || y == 7 || y == 8 || y == 10 || y == 12) {
      cout << "Yes";
    } else {
      cout << "No";
    }
  }
}
