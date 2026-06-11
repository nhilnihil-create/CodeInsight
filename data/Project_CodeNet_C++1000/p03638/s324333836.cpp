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
  ll h,w,n;cin>>h>>w>>n;
  vll a(0);vvll c(h,vll(w));
  rep(i,0,n){
    ll t;cin>>t;
    rep(j,0,t){
      a.push_back(i+1);
    }
  }

  rep(i,0,h){
    if(i%2){
      rep(j,0,w){
        c[i][j]=a[w*i+j];
      }
    }
    else{
      rep(j,0,w){
        c[i][w-j-1]=a[w*i+j];
      }
    }
  }
  rep(i,0,h){
    rep(j,0,w){
      cout<<c[i][j]<<" ";
    }
    cout<<endl;
  }
  
}
