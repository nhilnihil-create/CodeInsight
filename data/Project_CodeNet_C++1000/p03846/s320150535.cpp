#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mod 1000000007

int main(){
  ll n;
  cin>>n;
  ll a[n];
  ll cnt[n]={0};
  for(int i=0;i<n;i++){
    cin>>a[i];
    cnt[a[i]]++;
  }
  
  ll ans=1;
  //2^n/2
  for(int i=0;i<n/2;i++){
    ans=(ans*2)%mod;
  }
  
  bool isValid=true;
  if(n%2==1){
    if(cnt[0]!=1){
      isValid=false;
    }
    for(int i=2;i<n&&isValid;i=i+2){
      if(cnt[i]!=2){
        isValid=false;
      }
    }
  }else{
    for(int i=1;i<n&&isValid;i=i+2){
      if(cnt[i]!=2){
        isValid=false;
      }
    }
  }
  if(isValid){
  	cout<<ans<<endl;
  }else{
    cout<<"0"<<endl;
  }
  
  return 0;
}
