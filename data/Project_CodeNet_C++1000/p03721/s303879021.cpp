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
  ll n,k;cin>>n>>k;
  ll tmp=0;
  vvll s(n,vll(2));
  rep(i,0,n){
    cin>>s[i][0]>>s[i][1];
  }
  sort(s.begin(),s.end());
  ll i=0;
  while(tmp<k){
    if(k-tmp>s[i][1]){
      tmp+=s[i][1];
      i++;
    }
    else{
      tmp+=s[i][1];
      cout<<s[i][0]<<endl;
    }
  }
}
