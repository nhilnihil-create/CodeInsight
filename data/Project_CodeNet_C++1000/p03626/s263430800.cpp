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
ll roundd(ll x,ll n){
  if(x>n){return x%n;}
  else if(x<0){return x%n+n;}
  else return x;
}

int main(){
  ll n;string s,t;cin>>n>>s>>t;
  vb d(0);
  rep(i,0,n){
    if(s[i]==t[i]){d.push_back(1);}
    else{d.push_back(0);i++;}
  }
  ll ans;
  if(d[0]){ans=3;}
  else{ans=6;}
  rep(i,0,d.size()-1){
    if(d[i+1]&&d[i]){ans*=2;}
    else if(!d[i+1]&&d[i]){ans*=2;}
    else if(!d[i+1]&&!d[i]){ans*=3;}
    ans%=MOD;
  }
  cout<<ans<<endl;
}

