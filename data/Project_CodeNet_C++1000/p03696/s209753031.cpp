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

int N;
string S;

int main() {
  cin >> N;
  cin >> S;

  int op = 0;
  int cl = 0;
  rep(i, 0, S.size()) {
    char c = S[i];
    if (c == '(') {
      ++op;
    } else {
      if (op) {
        --op;
      } else {
        ++cl;
      }
    }
  }

  rep(i, 0, cl) { cout << '('; }
  cout << S;
  rep(i, 0, op) { cout << ')'; }
}
