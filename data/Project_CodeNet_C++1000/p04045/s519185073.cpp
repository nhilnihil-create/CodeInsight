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
  ll n,m;cin>>n>>m;
  vb d(10,false);
  rep(i,0,m){
    ll a;cin>>a;
    d[a]=true;
  }
  ll ans;
  rep(i,n,100000){
    string s=to_string(i);
    bool ok=true;
    rep(i,0,s.size()){
      ll t=s[i]-'0';
      if(d[t]){ok=false;}
    }
    if(ok){
      ans=i;break;
    }
  }
  cout<<ans<<endl;
}

