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
  if(n==1){
    cout<<"YES"<<endl;
    return 0;
  }
  vl a(n);
  rep(i,n)cin>>a[i];
  ll sum=0;
  rep(i,n)sum+=a[i];
  ll one=n*(n+1)/2;
  if(sum%one!=0){
    cout<<"NO"<<endl;
    return 0;
  }
  ll num=sum/one;
  ll count=0;
  vl kaisa(n);
  rep(i,n-1)kaisa[i]=a[i+1]-a[i];
  kaisa[n-1]=a[0]-a[n-1];
  rep(i,n){
    ll d=num-kaisa[i];
    if(d%n!=0||d/n<0){
      cout<<"NO"<<endl;
      return 0;
    }
    count+=d/n;
  }
  if(count==num){
    cout<<"YES"<<endl;
    return 0;
  }
  cout<<"NO"<<endl;
  return 0;
}