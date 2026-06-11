#include <bits/stdc++.h>
using namespace std;

#define NDEBUG
#ifdef DEBUG
#include "../cout11.h"
#undef NDEBUG
#endif
#include <cassert>

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

typedef long long ll;
typedef long double Double;
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> llll;
typedef pair<double,double> dd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<llll> vllll;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<long double> vD;

#define sz(a)  int((a).size())
#define pb  push_back
#define eb  emplace_back
#define FOR(var,from,to) for(int var=(from);var<=(to);++var)
#define rep(var,n)  for(int var=0;var<(n);++var)
#define rep1(var,n)  for(int var=1;var<=(n);++var)
#define repC2(vari,varj,n)  for(int vari=0;vari<(n)-1;++vari)for(int varj=vari+1;varj<(n);++varj)
#define repC3(vari,varj,vark,n)  for(int vari=0;vari<(n)-2;++vari)for(int varj=vari+1;varj<(n)-1;++varj)for(int vark=varj+1;vark<(n);++vark)
#define ALL(c)  (c).begin(),(c).end()
#define RALL(c)  (c).rbegin(),(c).rend()
#define tr(i,c)  for(auto i=(c).begin(); i!=(c).end(); ++i)
#define found(s,e)  ((s).find(e)!=(s).end())
#define mset(arr,val)  memset(arr,val,sizeof(arr))
#define mid(x,y) ((x)+((y)-(x))/2)
#define IN(x,a,b) ((a)<=(x)&&(x)<=(b))
#define cons make_pair
#define clamp(v,lo,hi) min(max(v,lo),hi)

template<class T> inline void amin(T & a, T const & b) { a = min(a, b); }
template<class T> inline void amax(T & a, T const & b) { a = max(a, b); }
template<typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
template<typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }


inline ll square(ll x) { return x * x; }
inline ll gcd(ll a, ll b) { while(a) swap(a, b%=a); return b; }
template <typename T>
inline T mod(T a, T b) { return ((a % b) + b) % b; }


bool solve(int N,ll A,ll B,ll C,ll D){
  ll w=N-1;
  ll dif=abs(B-A);
  ll delta=D+C;

  ll mx=D*w, mn=C*w;
  if (IN(dif, mn, mx)) return true;
  rep(i,w) {
    mx-=delta; mn-=delta;
    if (IN(dif, mn, mx)) return true;
  }
  return false;
}

int main() {
    int n,a,b,c,d; cin>>n>>a>>b>>c>>d;
    cout << (solve(n,a,b,c,d) ? "YES":"NO") << endl;
    return 0;
}
