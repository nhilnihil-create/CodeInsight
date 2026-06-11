#include <bits/stdc++.h>
template< typename T >
T mod_pow(T x, T n, const T &p) {
  if(x < 0) return 0;
  T ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= p;
    (x *= x) %= p;
    n >>= 1;
  }
  return ret;
}
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using P = pair<int, int>;
const double eps = 1e-8;
const ll MOD = 1000000007;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
template <typename T1, typename T2>
bool chmax(T1 &a, const T2 &b) {
  if(a < b) {a = b; return true;}
  return false;
}
template <typename T1, typename T2>
bool chmin(T1 &a, const T2 &b) {
  if(a > b) {a = b; return true;}
  return false;
}
template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}
template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  for(int i=0;i<((int)(v.size()));++i) {
    if(i) os << " ";
    os << v[i];
  }
  return os;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int n; cin >> n;
  string s; cin >> s;
  int sz = (int)(s.size());
  vvll dp(n+1, vll(n+1));
  dp[0][0] = 1;
  for(int i=0;i<(n);++i) {
    for(int j=0;j<(n);++j) {
      if(j != 0) {
        dp[i+1][j-1] += dp[i][j];
        dp[i+1][j-1] %= MOD;
      } else {
        dp[i+1][j] += dp[i][j];
        dp[i+1][j] %= MOD;
      }
      dp[i+1][j+1] += 2 * dp[i][j];
      dp[i+1][j+1] %= MOD;
    }
  }
  ll inv2 = mod_pow<ll>(2, MOD-2, MOD);
  ll now = 1;
  for(int i=0;i<(sz);++i) now *= inv2, now %= MOD;
  cout << dp[n][sz] * now % MOD << endl;
}
