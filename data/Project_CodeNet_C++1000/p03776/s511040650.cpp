#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>



#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;

ll c(ll a,ll b){
  if(a*b==0)return 1;
  ll res=1;
  rep(i,b){
    res=res*(a-i)/(i+1);
  }
  return res;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  double ok=0,ng=1e16;
  ll n;cin>>n;
  ll a,b;
  cin>>a>>b;
  vector<double>v(n);
  rep(i,n)cin>>v[i];
  auto check=[&](double k){
    auto tv=v;
    rep(i,n)tv[i]-=k;
    sort(all(tv),greater<double>());
    double su=0LL;
    rep(i,a){
      su+=tv[i];
    }
    rep(j,b+1){
      if(tv[j+a]>0)su+=tv[j+a];
    }
    if(su<0)return 0;
    return 1;
  };
  rep(i,100){
    double nn=(ng+ok)/2;
    if(check(nn))ok=nn;
    else ng=nn;
  }

  cout<<fixed<<setprecision(7)<<ok<<endl;
  double e=1e-2;
  auto tv=v;
  rep(i,n)tv[i]-=ok;
  sort(all(tv),greater<double>());
  //ll sum=0;
  if(abs(tv[a-1])<e){
    double d=tv[a-1];
    ll cnt=0,cnt2=0;
    rep(i,n)cnt+=(abs(tv[i]-d)<e);
    rep(i,a)cnt2+=(abs(tv[i]-d)<e);
    ll res=0LL;
    repi(i,cnt2,min(b-a,cnt-cnt2)+cnt2+1)res+=c(cnt,i);
    //cout<<d<<endl;
    //cout<<cnt<<cnt2<<endl;;
    //cout<<(1LL<<50)<<endl;
    cout<<res<<endl;
  }else {
    double d=tv[a-1];
    ll cnt=0,cnt2=0;
    rep(i,n)cnt+=(abs(tv[i]-d)<e);
    rep(i,a)cnt2+=(abs(tv[i]-d)<e);
    ll res=c(cnt,cnt2);
    //repi(i,cnt2,min(b-a,cnt-cnt2)+cnt2+1)res+=c(cnt,i);
    //cout<<d<<endl;
    //cout<<cnt<<cnt2<<endl;;
    //cout<<(1LL<<50)<<endl;
    cout<<res<<endl;

  }



  return 0;

}
