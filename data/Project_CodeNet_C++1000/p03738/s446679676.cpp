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

string A, B;

int main() {
  cin >> A >> B;
  if (A.size() > B.size()) {
    cout << "GREATER";
  } else if (A.size() < B.size()) {
    cout << "LESS";
  } else {
    rep(i, 0, A.size()) {
      if (A[i] > B[i]) {
        cout << "GREATER";
        return 0;
      } else if (A[i] < B[i]) {
        cout << "LESS";
        return 0;
      }
    }

    cout << "EQUAL";
  }
}
