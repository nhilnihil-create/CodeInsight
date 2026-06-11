#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const ll MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
/*ll f(ll x) {
  if (x == 1) return (ll)1;
  ll ans = x * f(x - 1) % MOD;
  return ans;
}*/
int main() {
  ll N, M;
  cin >> N >> M;
  ll ans = 1;
  for (ll i = 1; i <= N; i++) {
    ans *= i;
    ans %= MOD;
  }
  for (ll i = 1; i <= M; i++) {
    ans *= i;
    ans %= MOD;
  }
  if (N == M) ans = ans * 2 % MOD;
  if (1 < abs(N - M)) ans = 0;
  cout << ans << endl;
}