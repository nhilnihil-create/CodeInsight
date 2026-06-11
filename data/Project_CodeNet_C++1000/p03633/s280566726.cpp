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
ll fac[MAX], finv[MAX], inv[MAX];
ll gcd(ll a,ll b){
   if (a%b == 0){
        return(b);
    }
   else{
       return(gcd(b, a%b));
    }
}
//ax+by=gcd(a,b)を満たす(x,y)
ll extgcd(ll a,ll b,ll &x,ll &y){
    ll d=a;
    if(b==0){
      x=1,y=0;
    }
    else{
      d=extgcd(b,a%b,y,x);
      y-=(a/b)*x;
    }
    return d;
}
//最小公倍数
ll lcm(ll a,ll b){
   return (a  / gcd(a, b))*b;
}


int main(){
  ll n,ans=1LL;cin>>n;
  rep(i,0,n){
    ll a;cin>>a;
    ans=lcm(ans,a);
    
  }
  cout<<ans<<endl;
}
