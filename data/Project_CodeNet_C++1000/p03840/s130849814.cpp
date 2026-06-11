//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define bit(n,k) (((ll)n>>(ll)k)&1) /*nのk bit目*/
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
//const ll MOD=998244353LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
vl dx={-1,-1,-1,0,0,1,1,1};
vl dy={1,-1,0,1,-1,1,0,-1};

int main(){
  ll i,o,t,j,l,s,z;cin>>i>>o>>t>>j>>l>>s>>z;
  ll ans=0;
  ans+=o;
  if(i==0||j==0||l==0){
    ans+=i/2*2;
    ans+=j/2*2;
    ans+=l/2*2;
  }
  else {
    if(i%2==j%2&&j%2==l%2){
      ans+=i+j+l;
    }
    else {
      ans+=i+j+l-1;
    }
  }
  cout<<ans<<endl;
}
