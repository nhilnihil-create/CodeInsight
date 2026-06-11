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
ll modpow(ll a, ll n, ll mod) {
  
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main(){
  ll n;cin>>n;
  vl a(n);
  rep(i,n)cin>>a[i];
  sort(a.begin(),a.end());
  bool ans=true;
  if(n%2==1){
    rep(i,n){
      if(i==0){
        if(a[i]!=0)ans=false;
        continue;
      }
      if(i%2==1){
        if(a[i]!=a[i-1]+2)ans=false;
      }
      else{
        if(a[i]!=a[i-1])ans=false;
      }
    }
  }
  if(n%2==0){
    rep(i,n){
      if(i==0){
        if(a[0]!=1)ans=false;
        continue;
      }
      if(i%2==0){
        if(a[i]!=a[i-1]+2)ans=false;
      }
      else {
        if(a[i]!=a[i-1])ans=false;
      }
    }
  }
  if(ans==false){
    cout<<0<<endl;
    return 0;
  }
  ll k=(a[n-1]+1)/2;
  cout<<modpow(2,k,MOD)<<endl;
}