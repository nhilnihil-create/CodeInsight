#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
using namespace std;
typedef long long ll;
 
int main(){ 
  ll n,a,b;
  cin>>n>>a>>b;
  ll hp[n];
  rep(i, n){
    cin>>hp[i];}
 ll hpa[n];
  
  ll l=1;
  ll r=1000000000;
  ll ans=0;
  for(ll k=0;k<50;k++){
    ll p=(l+r)/2;
    ll cnt=0;
    rep(i, n){
     
      hpa[i]=max(hp[i]-b*p,(ll)0);
     cnt+=(hpa[i]+a-b-1)/(a-b);
    }
    if(cnt<=p){
      r=p;
    ans=p;}
    else{
      l=p;}
    }
  
    
    cout<<ans<<endl;
   
}