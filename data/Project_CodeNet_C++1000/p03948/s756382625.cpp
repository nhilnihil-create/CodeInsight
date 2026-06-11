#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,n) for (int i = a; i < (int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define whole(f,x,...) ([&](decltype((x)) whole) { \
    return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
template<typename T> bool chmin(T &a, const T &b) {if (a > b) { a = b; return true; }return false;}
template<typename T> bool chmax(T &a, const T &b) {if (a < b) { a = b; return true; }return false;}

using ll = int_fast64_t;

constexpr ll INF = (1e9);
constexpr ll MOD = (1e9+7);

int main() {
  int n, k; cin >> n >> k;
  vector<int> a(n); REP(i,n) cin >> a[i];
  vector<int> v(n);
  int min;
  min = a[0]; v[0] = 0;
  FOR(i, 1, n) {
    if (a[i] > min) v[i] = a[i] - min;
    else min = a[i];
  }
  whole(sort, v, greater<int>());
  int ans = 0;
  REP(i,n) {
    if (v[i] == v[0]) ans++;
  }
  cout << ans << endl;
  return 0;
}
