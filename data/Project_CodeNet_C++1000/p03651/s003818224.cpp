#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
template <typename T>
ll extGCD(T a, T b, T &x, T &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  ll d = extGCD(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int main() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  ll mx = 0;
  REP(i, N) cin >> A[i], chmax(mx, A[i]);
  if (N == 1) {
    if (A[0] == K) {
      cout << "POSSIBLE" << endl;
    } else {
      cout << "IMPOSSIBLE" << endl;
    }
    return 0;
  }
  ll x, y;
  ll tmp = extGCD(A[0], A[1], x, y);
  REP(i, N) tmp = extGCD(tmp, A[i], x, y);
  if (K % tmp == 0 && K <= mx) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}