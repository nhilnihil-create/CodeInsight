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

// -------------------------------------------------------
long long gcd(long long a, long long b) {
  if (b == 0) return a;

  return gcd(b, a % b);
}

long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

const int maxn = 1e5 + 1000;

ll N, K;
ll A[maxn];
ll maxa;

int main() {
  cin >> N >> K;
  rep(i, 0, N) {
    cin >> A[i];
    chmax(maxa, A[i]);
  }

  if (N == 1) {
    if (K == A[0]) {
      cout << "POSSIBLE" << endl;
      return 0;
    } else {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }

  if (K > maxa) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }

  ll g = gcd(A[0], A[1]);
  rep(i, 2, N) { g = gcd(g, A[i]); }

  rep(i, 0, N) {
    if (abs(K - A[i]) % g == 0) {
      cout << "POSSIBLE" << endl;
      return 0;
    }
  }

  cout << "IMPOSSIBLE" << endl;
  return 0;
}
