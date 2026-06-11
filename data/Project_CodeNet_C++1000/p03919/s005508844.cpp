// clang-format off
#include <bits/stdc++.h>
#define int long long
#define main signed main()
// #define main int main()
#define bye return 0
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
#define stlice(from, to) substr(from, (to) - (from) + 1)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vd = vector<double>;
using vvi = vector<vi>;
using vc = vector<char>;
using vs = vector<string>;
using vpii = vector<pii>;
template<typename A> using fn = function<A>;
constexpr int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
constexpr int MOD = 1000000007;
constexpr double PI = acos(-1);
constexpr int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
template<typename A, typename B> bool cmin(A &a, const B &b) { if (a > b) { a = b; return true; } else return false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { if (a < b) { a = b; return true; } else return false; }
namespace fpl {
  template<typename V, typename F> constexpr V fmap(V v, const F &f) { transform(all(v), v.begin(), f); return v; }
  template<typename V, typename F> constexpr V filterNot(V v, const F &f) { v.erase(remove_if(all(v), f), v.end()); return v; }
  template<typename V, typename F> constexpr V filter(V v, const F &f) { return filterNot(v, [&](typename V::value_type x) { return !f(x); }); }
  template<typename X, typename V, typename F> constexpr X fold(const X &x, const V &v, const F &f) { return accumulate(all(v), x, f); }
  template<typename V> constexpr typename V::value_type sum(const V &v) { return accumulate(all(v), 0); }
  constexpr bool odd(const int &n) { return n & 1; }
  constexpr bool even(const int &n) { return !odd(n); }
  template<typename V, typename F> constexpr bool andall(const V &v, const F &f) { for (auto &p : v) if (!f(p)) return false; return true; }
  template<typename V, typename F> constexpr bool orany(const V &v, const F &f) { for (auto &p : v) if(f(p)) return true; return false; }
  constexpr int gcd(int a, int b) { int c = 0; while (a) { c = a; a = b % a; b = c; } return b; }
  constexpr int pows(int a, int b) { int c = 1; while (b) { if (odd(b)) c *= a; b >>= 1; a *= a; } return c; }
}
using namespace fpl;
// clang-format on

main {
  int h, w;
  cin >> h >> w;
  rep(i, h) rep(j, w) {
    string s;
    cin >> s;
    if (s == "snuke") {
      cout << char(j + 'A') << i + 1 << endl;
      bye;
    }
  }
}
