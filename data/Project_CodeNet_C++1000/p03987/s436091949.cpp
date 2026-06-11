#include <bits/stdc++.h>
using namespace std;using ll=int_fast64_t;using ld=long double;using pll=pair<ll,ll>;using pld=pair<ld,ld>;
const ll INF=1LL<<60;void solve();int main(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(10);solve();}
#define foreach(i,a) for(auto &i:a)
#define SELECTOR(_1,_2,_3,_4,SELECT,...) SELECT
#define rep(...) SELECTOR(__VA_ARGS__,_rep2,_rep1,_rep0)(__VA_ARGS__)
#define _rep0(i,n) for(ll i=0;i<n;++i)
#define _rep1(i,k,n) for(ll i=k;i<n;++i)
#define _rep2(i,k,n,d) for(ll i=k;d!=0&&d>0?i<n:i>n;i+=d)
template<class T> vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<class... Ts> auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<class T> inline bool chmax(T &a,const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a,const T &b){if(a>b){a=b; return 1;} return 0;}

void solve(){
  ll n; cin>>n;
  vector<pll> XI(n);
  rep(i,n){
    ll x; cin>>x;
    XI[i]=make_pair(x,i);
  }


  sort(XI.begin(),XI.end());
  // xの値が小さいほうのindexから入れていく
  ll ans=0;
  set<ll> S{-1,n};
  foreach(p,XI){
    ll x,i; tie(x,i)=p;
    auto it1=S.insert(i).first;
    auto it2=it1;
    it1--; it2++;
    ll prev=*it1, next=*it2;
    ans+=x*(i-prev)*(next-i);
  }

  cout<<ans<<"\n";
}