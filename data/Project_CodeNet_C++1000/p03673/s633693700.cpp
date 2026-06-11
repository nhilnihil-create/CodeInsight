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

int n;
vector<int> vec, rev, ansvec;

int main() {
  cin >> n;
  repe(i, 1, n) {
    int a;
    cin >> a;
    if (i % 2 == 1) {
      rev.push_back(a);
    } else {
      vec.push_back(a);
    }
  }

  reverse(rev.begin(), rev.end());

  for (auto e : rev) {
    ansvec.push_back(e);
  }

  for (auto e : vec) {
    ansvec.push_back(e);
  }

  if (n % 2 == 0) {
    reverse(ansvec.begin(), ansvec.end());
  }

  for (auto e : ansvec) {
    cout << e << " ";
  }
}