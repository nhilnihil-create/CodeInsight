// see https://github.com/LumaKernel/vimfiles/tree/master/snippets/cp-cpp/temp.snip
/// --- .lumrc Template {{{ ///
// #define DEBUG
// #define assert(...)
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = tuple<ll, ll>;
using P3 = tuple<ll, ll, ll>;
using VI = vector<int>;
using VL = vector<ll>;
using VVI = vector<VI>;
using VVL = vector<VL>;
using VP = vector<P>;
using VS = vector<string>;

#define omajinai ios::sync_with_stdio(false),cin.tie(0)

#define FOR(i,a,b) for(int i=int(a);i<int(b);++i)
#define FORI(i,a,b) for(int i=int(a);i<=int(b);++i)
#define REP(i,n) FOR(i,0,n)
#define REPI(i,n) FORI(i,0,n)
#define RFOR(i,a,b) for(int i=int(b)-1;i>=int(a);--i)
#define RFORI(i,a,b) for(int i=int(b);i>=int(a);--i)
#define RREP(i,n) RFOR(i,0,n)
#define RREPI(i,n) RFORI(i,0,n)

#define ALL(a) begin(a),end(a)
#define UNIQUE(a) (a).erase(unique(ALL(a)),(a).end())
#define PB push_back
#define EACH(i,c) REP(i,(c).size())
#define REACH(i,c) RREP(i,(c).size())
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort(ALL(c))

#define BR cout<<"\n";

#ifdef DEBUG
#define dump(...) cerr<<"["<<__LINE__<< "] "<<#__VA_ARGS__<<" = "<<make_tuple(__VA_ARGS__)<<"\n";
#else
#define dump(...)
#endif

#define YES(x) cout<<((x)?"YES":"NO")<<"\n";
#define Yes(x) cout<<((x)?"Yes":"No")<<"\n";
#define yes(x) cout<<((x)?"yes":"no")<<"\n";

int __int_temp; ll __ll_temp; string __string_temp;
#define oini (omajinai, cin>>__int_temp, __int_temp)
#define oinl (omajinai, cin>>__ll_temp, __ll_temp)
#define oins (omajinai, cin>>__string_temp, __string_temp)
#define ini (cin>>__int_temp, __int_temp)
#define inl (cin>>__ll_temp, __ll_temp)
#define ins (cin>>__string_temp, __string_temp)

#define isInside(y,x) (0<=(y)&&(y)<h&&0<=(x)&&(x)<w)

#define fi(x) (get<0>(x))
#define se(x) (get<1>(x))
#define th(x) (get<2>(x))
#define fo(x) (get<3>(x))
#define fif(x) (get<4>(x))

template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '{'; EACH(i, v) o << v[i] << (i != (int)v.size()-1 ? ", " : ""); o << "}";  return o; }

template<int n, class...T> typename enable_if<(n>=sizeof...(T))>::type _ot(ostream &, tuple<T...> const &){}
template<int n, class...T> typename enable_if<(n< sizeof...(T))>::type _ot(ostream & os, tuple<T...> const & t){ os << (n==0?"":", ") << get<n>(t); _ot<n+1>(os, t); }
template<class...T> ostream & operator<<(ostream & os, tuple<T...> const & t){ _ot<0>(os, t); return os; }

template <typename T> inline void smax(T &a, T b) { a = a > b ? a : b; }
template <typename T> inline void smin(T &a, T b) { a = a < b ? a : b; }

template<typename T> inline int intlog2(T x);
template<> inline int intlog2(int x) { return x == 0 ? 0 : 32 - __builtin_clz(x); }
template<> inline int intlog2(ll x) { return x == 0 ? 0 : 64 - __builtin_clzll(x); }

constexpr double PI = acos(-1);

/// }}}--- ///

constexpr int INF = 1e9+1;
constexpr ll LINF = 1e18+1;
constexpr int MOD = 1e9+7;

// range add
// range sum
struct LST {
  VL data, lazy;
  int m;
  LST(int sz) {
    m = 1 << max(intlog2(sz), 1);
    data = VL(2*m-1, 0);
    lazy = VL(2*m-1, 0);
  }
  void eval(int k, int l, int r) {
    if(lazy[k]!=0) {
      data[k] += lazy[k] * (r - l);
      if(r-l>1) {
        lazy[k*2+1] += lazy[k];
        lazy[k*2+2] += lazy[k];
      }
      lazy[k] = 0;
    }
  }
  void add(int a, int b, ll x, int k = 0, int l=0, int r=-1) {
    if(r<0) r=m;
    if(b<=a) return;
    eval(k, l, r);
    if(b<=l||r<=a) return;
    if(a<=l&&r<=b) {
      lazy[k] += x;
      eval(k, l, r);
      return;
    }
    add(a, b, x, k*2+1, l, (l+r)>>1);
    add(a, b, x, k*2+2, (l+r)>>1, r);
  }
  ll get(int a, int b, int k=0, int l=0, int r=-1) {
    if(r<0) r=m;
    eval(k, l, r);
    if(b<=l||r<=a) return 0;
    if(a<=l&&r<=b) return data[k];
    return
      get(a, b, k*2+1, l, (l+r)>>1)+
      get(a, b, k*2+2, (l+r)>>1, r);
  }
};

vector<P3> ps;
int main() {
  int n=ini, m=ini;
  LST ecasdqina(m+1);
  REP(i, n) {
    ll l=ini, r=ini;
    ps.emplace_back(r-l+1, l, r);
  }
  SORT(ps);
  int pt = 0;
  FORI(i, 1, m) {
    while(pt<n && fi(ps[pt]) < i) {
      ecasdqina.add(max(fi(ps[pt])+1, se(ps[pt])), th(ps[pt])+1, 1);
      pt++;
    }
    ll ans = n - pt;
    int k = i;
    while(1) {
      if(k > m) break;
      ans += ecasdqina.get(k, k+1);
      k+=i;
    }
    cout << ans << endl;
  }
}
