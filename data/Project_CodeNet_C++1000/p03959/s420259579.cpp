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
  vl a(n),b(n);
  rep(i,n)cin>>a[i];
  rep(i,n)cin>>b[i];
  vector<bool>vec(n,true);
  vec[0]=false;
  vec[n-1]=false;
  vector<bool>vec1(n,true);
  vector<bool>vec2(n,true);
  vec1[0]=false;
  vec2[n-1]=false;
  rep(i,n-1){
    if(a[i+1]!=a[i]){
      vec[i+1]=false;
      vec1[i+1]=false;
    }
  }
  for(ll i=n-2;i>=0;i--){
    if(b[i+1]!=b[i]){
      vec[i]=false;
      vec2[i]=false;
    }
  }
  //rep(i,n){
    //cout<<vec[i]<<" "<<vec1[i]<<" "<<vec2[i]<<endl;
  //}
  rep(i,n){
    if(vec1[i]==false){
      if(a[i]>b[i]){
        cout<<0<<endl;
        return 0;
      }
    }
    if(vec2[i]==false){
      if(a[i]<b[i]){
        cout<<0<<endl;
        return 0;
      }
    }
    if(a[n-1]!=b[0]){
      cout<<0<<endl;
      return 0;
    }
  }
  ll ans=1;
  rep(i,n){
    if(vec[i]){
      ans*=min(a[i],b[i]);
      ans%=MOD;
    }
  }
  cout<<ans<<endl;
}