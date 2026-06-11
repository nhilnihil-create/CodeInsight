#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,n) for (int i = a; i < (int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define whole(f,x,...) ([&](decltype((x)) whole) { \
    return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
template<typename T> bool chmin(T &a, const T &b) {if (a > b) { a = b; return true; }return false;}
template<typename T> bool chmax(T &a, const T &b) {if (a < b) { a = b; return true; }return false;}

using ll = int_fast64_t;
using PII = pair<int, int>;

constexpr ll INF = (1e9);
constexpr ll MOD = (1e9+7);

int main() {
  ll h, w, n; cin >> h >> w >> n;
  map<PII, ll> mp;
  REP(i,n) {
    int a, b; cin >> a >> b;
    a--; b--;
    REP(j, 3) REP(k, 3) {
      if (a - j >= 0 && b - k >= 0
          && a - j < h-2 && b - k < w-2) mp[make_pair(a-j, b-k)]++;
    }
  }
  vector<ll> ans(10,0);
  for (const auto &p : mp) {
    ans[p.second]++;
  }
  ans[0] = (h-2)*(w-2) - whole(accumulate, ans, 0L);
  REP(i,10) cout << ans[i] << endl;
  return 0;
}
