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
const int INF=1e9+7;
inline ll mod(ll a, ll m) {
    return (a % m + m) % m;
}
int main(){
  ll n,ans=0;cin>>n;
  vll a(n),b(n);
  rep(i,0,n){
    cin>>a[i]>>b[i];
  }
  for(int i=n-1;i>=0;i--){
    if(mod(a[i]+ans,b[i])!=0){
      ans+=b[i]-mod(a[i]+ans,b[i]);
    }
  }
  cout<<ans<<endl;
}
