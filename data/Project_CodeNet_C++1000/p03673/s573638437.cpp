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
  ll n;cin>>n;
  vll a(n),b(n);
  rep(i,0,n){cin>>a[i];}
  if(n%2){
    rep(i,0,n/2+1){
      b[i]=a[n-1-i*2];
    }
    rep(i,n/2+1,n){
      b[i]=a[(i-n/2)*2-1];
    }
  }
  else{
    rep(i,0,n/2){
      b[i]=a[n-1-i*2];
    }
    rep(i,n/2,n){
      b[i]=a[(i-n/2)*2];
    }
  }
  rep(i,0,n){
    cout<<b[i]<<" ";
  }
  cout<<endl;
}

