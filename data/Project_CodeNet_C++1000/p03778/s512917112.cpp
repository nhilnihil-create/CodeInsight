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
const ll MOD = 1L<<32;
ll fac[MAX], finv[MAX], inv[MAX];

int main(){
  ll w,a,b,ans;cin>>w>>a>>b;
  if(b>a+w){ans=b-a-w;}
  else if(b+w<a){ans=a-b-w;}
  else{ans=0;}
  cout<<ans<<endl;
}


