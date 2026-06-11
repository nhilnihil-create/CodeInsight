//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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



signed main(){
  cin.tie(0);ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  int n,m;cin>>n>>m;
  VV<int> e(11*n,V<int>(0));

  rep(i,0,m){
    int a,b;cin>>a>>b;
    a--;b--;
    rep(j,1,11){
      e[11*a+j].pb(11*b+j-1);
      e[11*b+j].pb(11*a+j-1);
    }
  }

  V<int> used(11*n,0),ans(n,0);

  int qq;cin>>qq;
  V<int> v(qq),d(qq),c(qq);
  rep(i,0,qq)cin>>v[i]>>d[i]>>c[i];


  queue<int> q;
  repr(i,0,qq){  
    v[i]--;

    if(!used[11*v[i]+d[i]]){
      q.push(11*v[i]+d[i]);
      used[11*v[i]+d[i]]=1;
      if(!ans[v[i]])ans[v[i]]=c[i];
    }


    while(q.size()){
      int now=q.front();q.pop();

      for(auto&& nex:e[now]){
        if(!used[nex]){
          used[nex]=1;
          if(!ans[nex/11])ans[nex/11]=c[i];
          q.push(nex);
        }
      }
    }
  }


  rep(i,0,n){
    cout<<ans[i]<<ENDL;
  }
}
//! ( . _ . ) ! 
//CHECK overflow,vector_size,what to output?