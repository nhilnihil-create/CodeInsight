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

int main(){
  ll n,ave=0;cin>>n;
  vll a(n);
  rep(i,0,n){
    cin>>a[i];
    ave+=a[i];
  }
  ave/=n;
  ll ans1=0,ans2=0;
  rep(i,0,n){
    ans1+=(a[i]-ave)*(a[i]-ave);
    ans2+=(a[i]-ave-1)*(a[i]-ave-1);
  }
  cout<<min(ans1,ans2)<<endl;
}
