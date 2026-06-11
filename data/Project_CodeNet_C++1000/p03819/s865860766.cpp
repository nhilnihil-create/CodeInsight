// vvvvvvvvvvvv TEMPLATE vvvvvvvvvvvv
#include <bits/stdc++.h>
using namespace std; using ll = long long; using P = pair<ll, ll>;
const ll linf = 1e18; const double eps = 1e-12, pi = acos(-1);
#define FOR(i,a,b) for (ll i=(a),__last_##i=(b);i<__last_##i;i++)
#define RFOR(i,a,b) for (ll i=(b)-1,__last_##i=(a);i>=__last_##i;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define __GET_MACRO3(_1, _2, _3, NAME, ...) NAME
#define each(i,a) for (auto&& i : a)
#define rep(...) __GET_MACRO3(__VA_ARGS__, FOR, REP)(__VA_ARGS__)
#define rrep(...) __GET_MACRO3(__VA_ARGS__, RFOR, RREP)(__VA_ARGS__)
#define pb push_back
#define eb emplace_back
#define all(a) begin(a),end(a)
#define chmin(x,v) x = min(x, v)
#define chmax(x,v) x = max(x, v)
template<typename T> ll min(ll a, const T&& b) { return a < b ? a : b; }
template<typename T> ll min(const T&& a, ll b) { return a < b ? a : b; }
template<typename T> ll max(ll a, const T&& b) { return a > b ? a : b; }
template<typename T> ll max(const T&& a, ll b) { return a > b ? a : b; }
template<typename Head> void out(Head h) { cout << h << endl; } template<typename Head, typename... Tail>void out(Head h, Tail... t) { cout << h << " "; out(t...); }
template<typename T> istream& operator>>(istream& is, vector<T>& v) { each(x,v) is >> x; return is; }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) { rep(i,v.size()) { if (i) os << " "; os << v[i]; } return os; }
ostream& operator<<(ostream& os, const vector<string>& v) { rep(i,v.size()) { if (i) os << endl; os << v[i]; } return os; }
template<typename T> ostream& operator<<(ostream& os, const vector<vector<T>>& v) { rep(i,v.size()) { if (i) os << endl; os << v[i]; } return os; }
template<typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2>& p) { return os << "(" << p.first << ", " << p.second << ")"; }
struct yes_no : std::numpunct<char> { string_type do_truename() const { return "Yes"; } string_type do_falsename() const { return "No"; } };
void solve(); int main() {
  ios::sync_with_stdio(false); cin.tie(0); locale loc(locale(), new yes_no); cout.imbue(loc); cout << fixed << setprecision(10) << boolalpha;
  solve();
}
// ^^^^^^^^^^^^ TEMPLATE ^^^^^^^^^^^^

class Bit {
  ll n;
  vector<ll> v;
public:
  Bit(ll sz) : n((sz+1)*2), v((sz+1)*2, 0) {}
  // v[pos] += val
  void add(ll pos, ll val) {
    ++pos;
    while (pos < n) {
      v[pos] += val;
      pos += pos & -pos;
    }
  }
  // [l, r)
  ll find(ll l, ll r) {
    return find(r) - find(l);
  }
  // [0, pos)
  ll find(ll pos) {
    ll res = 0;
    while (pos >= 1) {
      res += v[pos];
      if (pos == 0) break;
      pos -= pos & -pos;
    }
    return res;
  }
};

void solve() {
  ll n, m; cin >> n >> m; ++m;
  map<ll, vector<P>> ev;
  rep(i, n) {
    ll l, r; cin >> l >> r; ++r;
    ev[r-l].eb(l, r);
  }
  ll sum = n;
  Bit bit(m);
  vector<ll> ans(m-1);
  rep(i, 1, m) {
    ll a = sum;
    for (ll j = 0; j < m; j += i) {
      a += bit.find(j+1);
    }
    ans[i-1] = a;
    each(p, ev[i]) {
      bit.add(p.first, 1);
      bit.add(p.second, -1);
      --sum;
    }
  }
  each(a, ans) cout << a << endl;
}
