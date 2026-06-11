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
  ll n;cin>>n;
  map<ll,ll>m;
  rep(i,0,n){
    ll a;cin>>a;
    m[a]++;
  }
  ll cnt=0;
  for(auto u:m){
    if(u.second>1){
      cnt+=u.second-1;
    }
  }
  cout<<(cnt%2?n-cnt-1:n-cnt)<<endl;
}

