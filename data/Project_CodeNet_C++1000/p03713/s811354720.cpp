#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;

int main(){
  ll h,w;cin>>h>>w;
  ll ans=min(h,w);
  if(h%3==0||w%3==0){
    cout<<0<<endl;return 0;
  }
  rep(i,1,h/2+1){
    ll tate=max(h-i,i),yoko=w/2;
    ll s1=tate*yoko,s2=tate*(w-yoko),s3=(h-tate)*w;
    ll smax=max(s1,max(s2,s3)),smin=min(s1,min(s2,s3));
    ans=min(ans,smax-smin);
    
  }
  rep(i,1,w/2+1){
    ll tate=h/2,yoko=max(w-i,i);
    ll s1=tate*yoko,s2=(h-tate)*yoko,s3=h*(w-yoko);
    ll smax=max(s1,max(s2,s3)),smin=min(s1,min(s2,s3));
    ans=min(ans,smax-smin);
  }
  cout<<ans<<endl;
}

