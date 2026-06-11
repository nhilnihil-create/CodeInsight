#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); ++i)
#define drep2(i, m, n) for(int i=int(m-1); i>=int(n); --i)
#define rep(i, n) rep2(i, 0, n)
#define drep(i, n) drep2(i, n, 0)
#define all(a) a.begin(), a.end()
#define fst first
#define snd second
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
const int INF = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;
template<typename T> inline bool chmin(T& a, T b) {if(a>b) {a=b; return true;} return false;}
template<typename T> inline bool chmax(T& a, T b) {if(a<b) {a=b; return true;} return false;}
inline int Log2(ll x) {int k; for(k=0; x>0; ++k) x>>=1; return k;} // number of binary digits
template<typename T> inline int count_between(vector<T>& a, T l, T r) {
  return lower_bound(all(a), r) - lower_bound(all(a), l); // [l, r)
}


int main() {
  ll N, K; cin >> N >> K;
  Vll a(N);
  rep(i, N) cin >> a[i];
  sort(all(a));
  
  int need = count_between(a, K, INFll);
  a.erase(a.end()-need, a.end());
  int M = N - need;

  VV dp(M+1, V(2*K));
  dp[0][0] = 1;

  rep(i, M) rep(k, 2*K) {
    dp[i+1][k] += dp[i][k];
    if (k+a[i] < 2*K) dp[i+1][k+a[i]] += dp[i][k];
  }

  rep(i, M) {
    V dp2 = dp[M];
    rep(k, K-a[i]) dp2[k+a[i]] -= dp2[k];
    bool isneed = false;
    rep(k, a[i]) if (dp2[K-a[i]+k]) isneed = true;
    if (isneed) ++need;
  }

  int ans = N - need;
  cout << ans << endl;
  return 0;
}
