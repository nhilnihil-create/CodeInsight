#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
long long combination(long n, long r, long long mod) {
  // nCrを返す　O(r)
  // 逆元はその場で対応
  if (n < r) swap(n, r);
  long long bunbo = 1;
  long cnt = r;
  while (0 < cnt) {
    bunbo *= cnt;
    cnt--;
  }
  if (bunbo == 0) return 1;
  long long bunsi = 1;
  cnt = 0;
  while (cnt < r) {
    bunsi *= (n - cnt);
    cnt++;
  }
  return bunsi / bunbo;
}
long long longpow(long long n, long long a, long long mod) {
  if (a == 0) return 1;
  if (a == 1) return n % mod;
  if (a % 2 == 1) return (n * longpow(n, a - 1, mod)) % mod;
  ll t = longpow(n, a / 2, mod) % mod;
  return (t * t) % mod;
}
int main() {
  int N, P;
  cin >> N >> P;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  int even = 0;
  REP(i, N) if (A[i] % 2 == 0) even++;
  int odd = N - even;
  if (odd == 0) {
    if (P == 1) {
      cout << 0 << endl;
    } else {
      cout << longpow(2, N, (ll)MOD * (ll)100000000) << endl;
    }
    return 0;
  }
  cout << longpow(2, N - 1, (ll)MOD * (ll)100000000) << endl;
}