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
//*
constexpr ll MOD = 1e9 + 7;
/*/
constexpr ll MOD = 998244353;
//*/
constexpr ll INF = 1e+18;
constexpr ld EPS = 1e-12L;
constexpr ld PI = 3.14159265358979323846L;
constexpr ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
constexpr ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }
template <typename S, typename T>
constexpr bool chmax(S &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename S, typename T>
constexpr bool chmin(S &a, const T &b) {
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

// {10, 3, 1, -5, 1} -> {3, 2, 1, 0, 1} + offset
template <typename T>
vector<T> CoordinateCompression(const vector<T> &x, int offset = 0) {
  int n = x.size();
  vector<T> y = x, ret(n);
  sort(y.begin(), y.end());
  y.erase(unique(y.begin(), y.end()), y.end());
  for (int i = 0; i < n; i++) {
    ret[i] = lower_bound(y.begin(), y.end(), x[i]) - y.begin() + offset;
  }
  return ret;
}

// {10, 3, 1, -5, 1} -> {3, 2, 1, 0, 1} + offset
// unzip: {-5, 1, 3, 10}
template <typename T>
vector<T> CoordinateCompression(const vector<T> &x, vector<T> &unzip, int offset = 0) {
  int n = x.size();
  vector<T> ret(n);
  unzip = x;
  sort(unzip.begin(), unzip.end());
  unzip.erase(unique(unzip.begin(), unzip.end()), unzip.end());
  for (int i = 0; i < n; i++) {
    ret[i] = lower_bound(unzip.begin(), unzip.end(), x[i]) - unzip.begin() + offset;
  }
  return ret;
}

// Binary Indexed Tree 0-indexed
struct BIT0 {
  ll n;
  vector<ll> bit;
  BIT0(ll n) : n(n), bit(n, 0) {}
  void add(ll a, ll w) {
    for (; a < n; a |= a + 1) {
      bit[a] += w;
    }
  }
  // v: 0-indexed, size = n
  void build(const vector<ll> &v) {
    n = v.size();
    bit = v;
    ll unit = 1;
    while (unit * 2 < n) {
      for (int i = unit * 2 - 1; i < n; i += unit * 2) {
        bit[i] += bit[i - unit];
      }
      unit <<= 1;
    }
  }
  ll sum(ll a) {
    ll ret = 0;
    for (; a >= 0; a = (a & (a + 1)) - 1) {
      ret += bit[a];
    }
    return ret;
  }
  // [a, b]
  ll sum(ll a, ll b) {
    return sum(b) - sum(a - 1);
  }
};


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  ll n, k;
  cin >> n >> k;
  vll a(n);
  rep(i, n){
    cin >> a[i];
    a[i] -= k;
  }
  vll cs(n+1, 0);
  rep(i, n){
    cs[i+1] = cs[i] + a[i];
  }
  cs = CoordinateCompression(cs);
  BIT0 bit(n+100);
  ll ans = 0;
  repb(i, n+1){
    ans += bit.sum(cs[i], n+50);
    bit.add(cs[i], 1);
  }
  print(ans);
}
