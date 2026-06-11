#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll mod = (1e9) + 7;
long long longpow(long long n, long long a, long long mod) {
  if (a == 0) return 1;
  if (a == 1) return n % mod;
  if (a % 2 == 1) return (n * longpow(n, a - 1, mod)) % mod;
  ll t = longpow(n, a / 2, mod) % mod;
  return (t * t) % mod;
}
int main() {
  ll N;
  cin >> N;
  vector<ll> A(N), T(N);
  REP(i, N) cin >> T[i];
  REP(i, N) cin >> A[i];
  if (N == 1) {
    if (T[0] != A[0]) {
      cout << 0 << endl;
      return 0;
    }
  }
  ll ans = 1;
  for (int i = 1; i < N - 1; i++) {
    if (T[i] == T[i - 1] && A[i] == A[i + 1]) {
      ans *= min<ll>(A[i], T[i]);
      ans %= mod;
      continue;
    }
    if (T[i - 1] < T[i] && A[i + 1] < A[i]) {
      if (T[i] == A[i]) continue;
    }
    if (T[i - 1] < T[i]) {
      if (A[i] < T[i]) {
        ans = 0;
      }
    }
    if (A[i] > A[i + 1]) {
      if (A[i] > T[i]) {
        ans = 0;
      }
    }
  }
  cout << ans << endl;
}