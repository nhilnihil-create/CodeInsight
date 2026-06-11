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

ll N;
ll T[200];

long long gcd(long long a, long long b) {
  if (b == 0) return a;

  return gcd(b, a % b);
}

long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

int main() {
  cin >> N;
  ll ans = 1;
  rep(i, 0, N) {
    cin >> T[i];
    ans = lcm(ans, T[i]);
  }
  cout << ans << endl;
}
