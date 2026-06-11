//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define PI 3.14159265359
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
const long long INF= 1e+18+1;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll> >vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
const ll MOD=1000000007LL;
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main(){
  ll n;cin>>n;
  string s,t;cin>>s>>t;
  for(ll i=0;i<=n;i++){
    bool ans=true;
    rep(j,n-i){
      if(s[i+j]!=t[j])ans=false;
      //cout<<s[i+j]<<" "<<t[j]<<endl;
    }
    if(ans){
      cout<<n+i<<endl;
      return 0;
    }
  }
}