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

int N;
int odd, mul2, mul4;

int main() {
  cin >> N;
  rep(i, 0, N) {
    int a;
    cin >> a;
    if (a % 4 == 0) {
      ++mul4;
    } else if (a % 2 == 0) {
      ++mul2;
    } else {
      ++odd;
    }
  }

  if (mul2 > 0) {
    mul2 = 1;
  }

  bool can = mul2 + odd <= mul4 + 1;

  if (can) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}
