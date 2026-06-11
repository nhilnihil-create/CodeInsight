// template version 1.15
using namespace std;
#include <bits/stdc++.h>

// varibable settings
#define int long long
const int INF=1e18;

// define basic macro {{{
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)((b)-1);i>=(int)(a);--i)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(i,a) for (auto&& i : a)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(a, b, c) make_tuple(a, b, c)
#define divceil(a,b) ((a)+(b)-1)/(b)
#define is_in(x, a, b) ((a)<=(x) && (x)<(b))
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define ub upper_bound
#define lb lower_bound
#define posl(A, x) (lower_bound(all(A), x)-A.begin())
#define posu(A, x) (upper_bound(all(A),x)-A.begin())
template<class T> inline void chmax(T &a, const T &b) { if((a) < (b)) (a) = (b); }
template<class T> inline void chmin(T &a, const T &b) { if((a) > (b)) (a) = (b); }

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;

template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

void sputs(){}
template <class Head, class... Tail>
void sputs(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(Tail) == 0) { cout << endl; }
  else { cout << " "; }
  sputs(std::move(tail)...);
}

#if defined(PCM) || defined(LOCAL)
  #include "lib/dump.hpp"
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif
//}}}
#define N 31
string to_bin(int n, int d){
  // nをd桁の2進数で表示する。
  stringstream ss;
  ss << bitset<N>(n);
  return ss.str().substr(N-d, d);
}
// int d = (32 - __builtin_clz(n));  // 桁数
// int f = N - d; to_bin()で返ってきた文字列で最初に1が立っているindex


signed main() {
  int n;cin>>n;
  int k;cin>>k;
  vi a(n),b(n);
  rep(i,n)cin>>a[i]>>b[i];
  dump(to_bin(k, 10));

  int ans = -INF;
  int res = 0;
  rep(i, n){
    if (((a[i])&~k)==0) res += b[i];
  }
  chmax(ans, res);
  dump(ans);

  rep(d, 0, 31){
    // d桁目を0
    if (k>>d&1){
      int res = 0;
      rep(i, n){
        dump(i, a[i]>>(d+1), k>>(d+1));
        if (((a[i]>>(d+1))&(~(k>>(d+1))))==0 && !(a[i]>>d&1)) res += b[i];
      }
      dump(d, res);
      chmax(ans, res);
    }
  }
  cout << ans << endl;

  return 0;
}
