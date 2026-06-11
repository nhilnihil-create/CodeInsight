#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef vector<pair<ll,ll> > vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>(b);--i)
const int MOD = 1000000007;
const int MAX = 510000;

int main(){
  ll n,x,ans=0;cin>>n>>x;
  vll a(n);
  rep(i,0,n){cin>>a[i];}
  if(a[0]>x){ans+=a[0]-x;a[0]=x;}
  rep(i,0,n-1){
    if(a[i]+a[i+1]>x){
      ans+=a[i]+a[i+1]-x;
      a[i+1]-=(a[i]+a[i+1]-x);
    }
  }
  cout<<ans<<endl;
}

