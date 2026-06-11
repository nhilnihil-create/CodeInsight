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
  ll n,a,b,ans=0;cin>>n>>a>>b;
  vll x(n);
  rep(i,0,n){cin>>x[i];}
  rep(i,0,n-1){
    if((x[i+1]-x[i])*a>b)ans+=b;
    else ans+=(x[i+1]-x[i])*a;
  }
  cout<<ans<<endl;
}

