using namespace std;
#include <iostream>
#include <bits/stdc++.h>

#define infile "../test/sample-1.in"
#define int long long
// #define INF 2147483647
#define INF 1000000000000000000LL
#define MOD 1000000007LL

// {{{ define basic macro
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) repi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)(b-1);i>=(int)(a);--i)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)

#define foreach(x,a) for(auto& (x) : (a) )
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)

#define all(x) (x).begin(),(x).end()
#define sum(v) accumulate(all(v), 0)
#define sz(x) ((int)(x).size())
template<class T> inline void chmax(T &a, const T &b) { if(a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if(a > b) a = b; }
// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
#define fill(x,y) memset(x,y,sizeof(x))
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define ten(n) ((int)1e##n)

template <class T = int>
T in() {T x; cin>>x; return (x);}

struct Fast {
  Fast(){
    std::cin.tie(0);
    ios::sync_with_stdio(false);
  }
} fast;
// }}}
//{{{ dump macro
#ifdef PCM
  #include "dump.hpp"
#else
  #define dump(...) 42
  #define dump_1d(...) 42
  #define dump_2d(...) 42
#endif
//}}}
//{{{ others
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;
template<typename T>
using PQ = priority_queue<T, vector<T>, greater<T>>;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};
//}}}


int solve(){
  int n,t;cin>>n>>t;
  int a[n];
  rep(i, n){ cin>>a[i]; }

  int m[n];
  m[0]=a[0];
  int b[n];
  b[0] = 0;
  int v = 1;
  rep(i, 1, n){
    m[i] = min(a[i], m[i-1]);
    b[i] = a[i]-m[i-1];
    chmax(v, b[i]);
  }
  dump_1d(a, n);
  dump_1d(m, n);
  dump_1d(b, n);
  dump(v);

  int cnt=0;
  rep(i, n){
    if(b[i]==v) cnt++;
  }
  cout << cnt << endl;


  return 0;
}

int test(){ //{{{
  return 0;
}
//}}}

signed main() { //{{{
#ifdef INPUT_FROM_FILE
  std::ifstream in(infile);
  std::cin.rdbuf(in.rdbuf());
#endif
#ifdef PCM
  test();
#endif
  solve();
  return 0;
} //}}}
