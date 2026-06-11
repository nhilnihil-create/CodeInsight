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
  int n, m; cin >> n >> m;
  vector<ll> x(n); REP(i,n) cin >> x[i];
  vector<ll> y(m); REP(i,m) cin >> y[i];
  ll xsum = 0, ysum = 0;
  REP(i,n) xsum += (2*i-n+1)%MOD * x[i]%MOD;
  REP(i,m) ysum += (2*i-m+1)%MOD * y[i]%MOD;
  cout << xsum%MOD * (ysum%MOD) %MOD << endl;
  return 0;
}
