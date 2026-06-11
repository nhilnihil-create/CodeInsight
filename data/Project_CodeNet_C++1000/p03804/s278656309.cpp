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
  ll n,m;cin>>n>>m;
  vector<string> a(n),b(m);
  rep(i,0,n){cin>>a[i];}
  rep(i,0,m){cin>>b[i];}
  if(a==b){
        cout<<"Yes"<<endl;
        return 0;
      }
  rep(i,0,n-m){
    rep(j,0,n-m){
      bool ok=true;
      rep(x,0,m){
        rep(y,0,m){
          if(a[i+x][j+y]!=b[x][y])ok=false;
        }
      }
      if(ok){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
  cout<<"No"<<endl;return 0;
}

