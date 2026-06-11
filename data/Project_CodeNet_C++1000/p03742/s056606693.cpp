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
  ll x, y; cin >> x >> y;
  if (abs(x-y) <= 1) cout << "Brown\n";
  else cout << "Alice\n";
  return 0;
}
