#include <bits/stdc++.h>
using namespace std;using ll=int_fast64_t;using ld=long double;using pll=pair<ll,ll>;using pld=pair<ld,ld>;
const ll INF=1LL<<60;void solve();int main(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(10);solve();}
#define fi first
#define se second
#define SELECTOR(_1,_2,_3,_4,SELECT,...) SELECT
#define rep(...) SELECTOR(__VA_ARGS__,_rep2,_rep1,_rep0)(__VA_ARGS__)
#define _rep0(i,n) for(ll i=0;i<n;++i)
#define _rep1(i,k,n) for(ll i=k;i<n;++i)
#define _rep2(i,k,n,d) for(ll i=k;d!=0&&d>0?i<n:i>n;i+=d)
template<class T> vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<class... Ts> auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<class T> inline bool chmax(T &a,const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a,const T &b){if(a>b){a=b; return 1;} return 0;}
template<class T> void contout(const T &v){for(auto it=v.begin();it!=v.end();++it,cout<<(it!=v.end()?" ":"\n"))cout<<*it;}

template<class T,class F>
constexpr T bisection(T l,T r,F f,bool left=true,bool discrete=true){
  T eps=discrete?1:pow(10,-12);
  if((!left)^f(r)) return left?r:r+1;
  if(left^f(l)) return left?l-1:l;
  while(r-l>eps){
    T h=(l+r)/2;
    if((!left)^f(h)) l=h;
    else r=h;
  }
  return discrete?left?l:r:(l+r)/2;
}

void solve(){
  ll n,k; cin>>n>>k;
  vector<ll> A(n);
  rep(i,n) cin>>A[i];
  sort(A.begin(),A.end());

  auto check=[&](ll x){
    vector<ll> dp(k,0);
    dp[0]=1;
    rep(i,n){
      if(i==x) continue;
      vector<ll> newdp=dp;
      ll a=A[i];
      rep(j,k){
        if(j+a<k) newdp[j+a]=max(dp[j+a],dp[j]);
      }
      dp=newdp;
    }
    return *max_element(dp.begin()+max((ll)0,k-A[x]),dp.end());
  };
  cout<<bisection((ll)0,n-1,check,false)<<"\n";
}