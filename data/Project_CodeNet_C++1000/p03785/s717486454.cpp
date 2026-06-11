#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef vector<pair<ll,ll> > vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
const int MOD=1e9+7;


int main(){
  ll n,c,k,ans=1;cin>>n>>c>>k;
  vll t(n);
  rep(i,0,n){
    cin>>t[i];
  }
  sort(t.begin(),t.end());
  int j=0,tmp=t[j]+k,p=0;
  rep(i,0,n){
    if(p<c&&tmp>=t[i]){
      p++;
    }
    else{
      ans++;j=i;p=1;
      tmp=t[j]+k;
    }
  }
  cout<<ans<<endl;
}
