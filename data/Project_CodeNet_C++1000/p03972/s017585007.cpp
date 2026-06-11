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
using Vbo = vector<bool>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using VVbo = vector<Vbo>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
template<typename T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; } return false; }
template<typename T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; } return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &v) { for (auto &e : v) is >> e; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &v) { for (auto &e : v) os << e << " "; return os; }
template<typename T> inline int count_between(vector<T> &a, T l, T r) { return lower_bound(all(a), r) - lower_bound(all(a), l); } // [l, r)
inline int Log2(ll x) { int k; for (k = 0; x > 0; ++k) x >>= 1; return k; } // number of binary digits
const int INF  = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS   = 1e-10;
const int MOD  = int(1e9)+7;


int main() {
  ll w, h; cin >> w >> h;
  vector<P> pq(w+h);
  rep(i, w) {
    int x; cin >> x;
    pq[i] = P(x, 0);
  }
  rep(i, h) {
    int x; cin >> x;
    pq[w+i] = P(x, 1);
  }
  sort(all(pq));

  ll ans = 0;
  Vll rest(2);
  rest[0] = w+1;
  rest[1] = h+1;
  int cnt = 0;
  for (auto &p : pq) {
    int x, i;
    tie(x, i) = p;
    cnt += rest[i^1];
    ans += rest[i^1] * x;
    --rest[i];
  }

  cout << ans << endl;
  return 0;
}
