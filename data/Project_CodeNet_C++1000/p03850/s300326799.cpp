#include<bits/stdc++.h>
using namespace std;
struct _IO{_IO(){ios::sync_with_stdio(0);cin.tie(0);}}_io;

typedef long long ll;
typedef long double db;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef tuple<int, int, int> t3;
typedef map<int, int> mi;
#define fi first
#define se second
#define vt vector
#define be begin()
#define ed end()
#define sz size()
#define cl clear()
#define pb push_back
#define eb emplace_back
#define is insert
#define all(x) x.begin(), x.end()
#define lb(v, x) lower_bound(v.begin(), v.end(), x)
#define lbi(v, x) (lb(v, x) - v.begin())
#define tp(t, x, y) t x, y; tie(x, y)
#define tp3(t, x, y, z) t x, y, z; tie(x, y, z)
#define mp make_pair
#define mt make_tuple
#define co const
#define fc(x) for(int x = 1, _end = ri(); x <= _end; x++)
void uni(vi &v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }

db rd() { db x; cin >> x; return x; }
ll ri() { ll x; cin >> x; return x; }
string rs() { string s; cin >> s; return s; }
pi rpi() { pi x; cin >> x.fi >> x.se; return x; }
vi rvi(int n, int f = 0) { vi v(n + f); for (int i = f; i < v.size(); i++) cin >> v[i]; return v; }
void pr() {}; template <class T, class ...U> void pr(T x, U ...y) { cout << x << ' ', pr(y...); }
void prl() { cout << '\n'; }; template <class T, class ...U> void prl(T x, U ...y) { cout << x << ' ', prl(y...); }
void pr(const vi &v, int f = 0) { for (int i = f; i < v.size(); i++) cout << v[i] << ' '; }
void prl(const vi &v, int f = 0) { pr(v, f); cout << '\n'; }
void kk() { cerr << endl; }; template <class T, class ...U> void kk(T x, U ...y) { cerr << x << ' ', prl(y...); }

#define rep(i, l, r) for (int i = (l); i < (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)

const int N = 3e5 + 5, M = 1e9 + 7;
int main() {
  int n = ri();
  ll lst = 0;
  vt<ll> a;
  rep(i, 0, n) {
    int flg = 1;
    if (i) flg = rs() == "+";
    int x = ri();
    if (flg) lst += x;
    else a.pb(lst), a.pb(-x), lst = 0;
  }
  if (lst) a.pb(lst);
  vt<ll> b(a.sz + 1);
  rep(i, 0, a.sz) {
    b[i+1] = b[i] + a[i];
  }
  ll ans = b[a.sz], sum = abs(a.back());
  per(i, a.sz - 1, 1) {
    if (a[i-1] > 0) sum += a[i-1];
    else {
      if (a[i] > 0) ans = max(ans, sum - 2 * a[i] + a[i-1] + b[i-1]);
      else ans = max(ans, sum + a[i-1] + b[i-1]);
      sum -= a[i-1];
    }
  }
  prl(ans);
}
