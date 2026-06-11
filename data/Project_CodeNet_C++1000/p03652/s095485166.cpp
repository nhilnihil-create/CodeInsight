#pragma region template
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vld = vector<ld>;
using vvld = vector<vld>;
using vvvld = vector<vvld>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
template <typename T>
using pqrev = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, n) for (ll i = 0, i##_end = (n); i < i##_end; i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repr(i, a, b) for (ll i = (a), i##_end = (b); i < i##_end; i++)
#define reprb(i, a, b) for (ll i = (b)-1, i##_end = (a); i >= i##_end; i--)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((ll)(x).size())
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
const ll INF = 1e+18;
const ld EPS = 1e-12L;
const ld PI = acos(-1.L);
inline ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
inline ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }
template <typename S, typename T>
inline bool chmax(S &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename S, typename T>
inline bool chmin(S &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
#ifdef OJ_LOCAL
#include "dump.hpp"
#else
#define dump(...) ((void)0)
#endif
template <typename T>
bool print_(const T &a) {
  cout << a;
  return true;
}
template <typename T>
bool print_(const vector<T> &vec) {
  for (auto &a : vec) {
    cout << a;
    if (&a != &vec.back()) {
      cout << " ";
    }
  }
  return false;
}
template <typename T>
bool print_(const vector<vector<T>> &vv) {
  for (auto &v : vv) {
    for (auto &a : v) {
      cout << a;
      if (&a != &v.back()) {
        cout << " ";
      }
    }
    if (&v != &vv.back()) {
      cout << "\n";
    }
  }
  return false;
}
void print() { cout << "\n"; }
template <typename Head, typename... Tail>
void print(Head &&head, Tail &&... tail) {
  bool f = print_(head);
  if (sizeof...(tail) != 0) {
    cout << (f ? " " : "\n");
  }
  print(forward<Tail>(tail)...);
}
#pragma endregion


ll n, m;
const int MAX = 300;
ll a[MAX][MAX];

// minimum x (C(x) == true)
ll solve() {
  vll p(n, 0);
  set<ll> st;
  ll ans = INF;
  rep(i, m){
    vll cnt(m+1, 0);
    rep(j, n){
      cnt[a[j][p[j]]]++;
    }
    ll ma = 0;
    ll mai = 0;
    rep(j, m+1){
      if(chmax(ma, cnt[j])){
        mai = j;
      }
    }
    chmin(ans, ma);
    st.emplace(mai);
    rep(j, n){
      while(st.count(a[j][p[j]])){
        p[j]++;
      }
    }
  }
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  cin >> n >> m;
  rep(i, n)rep(j, m) cin >> a[i][j];
  print(solve());
}
