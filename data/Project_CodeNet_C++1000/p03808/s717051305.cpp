#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n;cin>>n;
  ll a[n];
  ll s=0,t=0;
  for(ll i=0;i<n;i++){
    cin>>a[i];
    s+=a[i];
    t+=i+1;
  }
  if(s%t!=0){
    cout<<"NO"<<endl;
    return 0;
  }
  s/=t;
  ll cnt=0;
  for(ll i=0;i<n-1;i++){
    if(a[i]<a[i+1]){
      if(a[i+1]-a[i]!=s){
        cout<<"NO"<<endl;
        return 0;
      }
    }
    else{
      if((s+a[i]-a[i+1])%n!=0){
        cout<<"NO"<<endl;
        return 0;
      }
      cnt+=(s+a[i]-a[i+1])/n;
    }
    if(cnt>s){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
}