//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ld = long double;
template<typename T> using V = vector<T>;
template<typename T> using VV = vector<vector<T>>;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,a,n) for(ll i=a;i<(ll)(n);++i)
#define repr(i,a,n) for(ll i=n-1;(ll)a<=i;--i)
#define ENDL '\n'
typedef pair<int,int> Pi;
typedef pair<ll,ll> PL;
constexpr ll mod = 1000000007;
constexpr ll INF = 1000000099;
constexpr ll LINF = (ll)(1e18 +99);
const vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
template<typename T,typename U> inline bool chmin(T& t, const U& u){if(t>u){t=u;return 1;}return 0;}
template<typename T,typename U> inline bool chmax(T& t, const U& u){if(t<u){t=u;return 1;}return 0;}
template<typename T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}

template<typename T,typename Y> inline T mpow(T a, Y n) {
  T res = 1;
  for(;n;n>>=1) {
    if (n & 1) res = res * a;
    a = a * a;
  }
  return res;
}

template<typename T,typename Y>
ostream& operator<<(ostream& os,const pair<T,Y>& p){
  return os<<"{"<<p.fs<<","<<p.sc<<"}";
}
template<typename T> ostream& operator<<(ostream& os,const V<T>& v){
  os<<"{";
  for(auto e:v)os<<e<<",";
  return os<<"}";
}
template<typename ...Args>
void debug(Args&... args){
  for(auto const& x:{args...}){
    cerr<<x<<' ';
  }
  cerr<<ENDL;
}

VV<int> e;
V<ll> v;

bool dfs(int now,int pre){
  if(siz(e[now])==1)return true;

  ll sum=0,nex,rem;
  V<ll> c(0);
  for(auto&& to:e[now]){
    if(to==pre)continue;
    if(!dfs(to,now))return false;

    c.pb(v[to]);
    sum+=v[to];
  }
  if(sum<v[now])return false;

  nex=2*v[now]-sum;
  if(pre==-1 && nex!=0)return false;  
  
  rem=(sum-nex);
  v[now]=nex;

  rep(i,0,siz(c)){
    if(c[i]>rem/2)nex-=c[i]-(rem/2);
  }

  if(nex<0)return false;
  else return true;
}

signed main(){
  cin.tie(0);cerr.tie(0);ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  ll n;cin>>n;
  e.assign(n,V<int>(0));
  v.resize(n);

  rep(i,0,n)cin>>v[i];
  rep(i,0,n-1){
    int a,b;cin>>a>>b;
    a--;b--;
    e[a].pb(b);
    e[b].pb(a);
  }

  if(n==2){
    if(v[0]==v[1])cout<<"YES"<<ENDL;
    else cout<<"NO"<<ENDL;
    return 0;
  }

  rep(i,0,n){
    if(siz(e[i])>1){
      if(dfs(i,-1))cout<<"YES"<<ENDL;
      else cout<<"NO"<<ENDL;
      return 0;
    }
  }

}
//! ( . _ . ) ! 
//CHECK overflow,vector_size,what to output?
