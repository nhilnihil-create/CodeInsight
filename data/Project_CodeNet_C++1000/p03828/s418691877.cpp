//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const int INF= 1e9+5;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//素因数分解O(√n)
map<ll,ll>M;
void prime_factor(int n){
  for(int i=2;i*i<=n;i++){
    while(n%i==0){
      M[i]++;
      n/=i;
    }
  }
  if(n!=1)M[n]++;;
  return;
}

int main(){
  ll n;cin>>n;
  for(int i=1;i<=n;i++){
     prime_factor(i);
  }
  ll ans=1;
  for(auto p:M){
   if(p.first==1)continue;
    ans*=p.second+1;
    ans%=MOD;
  }
  cout<<ans<<endl;
}
    
  