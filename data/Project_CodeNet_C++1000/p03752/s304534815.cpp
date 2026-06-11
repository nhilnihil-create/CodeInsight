#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll gcd(ll a, ll b){
  if(b == 0){
    return a;
  }
  else{
    return gcd(b,(a%b));
  }
}
ll lcm(ll a,ll b){
  return a/gcd(a,b)*b;
}

int main(){
  int n,k;
  cin>>n>>k;
  ll vec[n-1];
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  int bitb[n];
  ll a=0,b=0,ma=vec[0];
  ll ans=150000000000;
  for(int bit=0;bit<(1<<n-1);bit++){
    for(int i=0;i<n-1;i++){
      if(bit&(1<<i)){
        bitb[i]=1;
        b++;
      }
      else{
        bitb[i]=0;
      }
    }
    if(b<k-1){
      b=0;
      continue;
    }
    //cout<<bit<<endl;
    b=0;
    for(int i=1;i<n;i++){
      if(bitb[i-1]==1){
        if(ma>=vec[i]){
          a+=ma+1-vec[i];
          b++;
        }
      }
      ma=max(ma,vec[i]);
      if(b==1){
        ma=ma+1;
        b=0;
      }
    }
    ma=vec[0];
    ans=min(ans,a);
    if(ans==a){
      //cout<<bit<<" "<<a<<endl;
    }
    a=0;
  }
  cout<<ans<<endl;
}