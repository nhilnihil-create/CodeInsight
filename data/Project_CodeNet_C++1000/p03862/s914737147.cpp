#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll n,x;
  cin>>n>>x;
  ll ans=0;
  ll a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  
  for(int i=0;i<n-1;i++){
    ll t=a[i]+a[i+1];
    if(t>x){
      ll diff=t-x;
      if(a[i+1]<diff){
 		a[i+1]=0;
      }else{
        a[i+1]=a[i+1]-diff;
      }
      ans+=diff;
    }
      
  }
  cout<<ans<<endl;
  return 0;
}