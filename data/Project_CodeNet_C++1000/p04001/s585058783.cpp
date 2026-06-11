#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll keta(ll n){
  ll k=0;
  while(n!=0){
    n/=10;
    k++;
  }
  return k;
}  

int main()
{
  ll N; cin>>N;
  ll K=keta(N);
  
  ll ans=0;
  rep(i,1<<(K-1)){
    ll N2=N;
    ll hoge=1;
    rep(j,K-1){
      hoge*=10;
      if(i&(1<<j)){
        ans+=N2%hoge;
        N2/=hoge;
        hoge=1;
      }
      //cout<<N2<<" "<<ans<<endl;
    }
    ans+=N2;
  }
  cout<<ans<<endl;
  return 0;
}
