#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

const double pi = 3.141592653589793;
// -------------------------------------------------------

int N;
int a[101010];
int m2, m4, odd;

int main() {
  cin >> N;
  rep(i, 0, N) {
    cin >> a[i];
    if (a[i] % 4 == 0) {
      ++m4;
    } else if (a[i] % 2 == 0) {
      ++m2;
    } else {
      ++odd;
    }
  }

  if (m2 == 0) {
    if (odd <= m4 + 1) {
      cout << "Yes" << endl;
      return 0;
    } else {
      cout << "No" << endl;
      return 0;
    }
  } else {
    if (odd <= m4) {
      cout << "Yes" << endl;
      return 0;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
}
