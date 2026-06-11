//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
int main(){
  ll h,w;
  cin>>h>>w;
  if(h%3==0||w%3==0){
    cout<<0<<endl;
    return 0;
  }
  ll ans=min(h,w);
  if(h==1 ||w==1){
    cout<<ans<<endl;
    return 0;
  }
  ll y;
  for(ll x=1;x<w;x++){
    y=h/2;
    ans=min(ans,max({abs(h*x-y*(w-x)),abs(h*x-(h-y)*(w-x)),abs(y*(w-x)-(h-y)*(w-x))}));
  }
  swap(h,w);
  for(ll x=1;x<w;x++){
    y=h/2;
    ans=min(ans,max({abs(h*x-y*(w-x)),abs(h*x-(h-y)*(w-x)),abs(y*(w-x)-(h-y)*(w-x))}));
  }
  cout<<ans<<endl;
}
  
  