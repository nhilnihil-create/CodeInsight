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

ll N;
ll T[1000];
ll M;
ll P[1000], X[1000];

int main() {
  cin >> N;
  ll sum = 0;
  rep(i, 0, N) {
    cin >> T[i];
    sum += T[i];
  }
  cin >> M;
  rep(i, 0, M) { cin >> P[i] >> X[i]; }

  rep(i, 0, M) { cout << sum + (X[i] - T[P[i] - 1]) << endl; }
}
