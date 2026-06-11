#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n,k;
  ll a[100009],b[100009];

  cin>>n>>k;
  for(int i=0;i<n;i++){
    cin>>a[i]>>b[i];
  }

  ll ans=0;
  for(int i=31;i>=0;i--){
    ll now=k,sum=0;
    if((k>>i)&1){
      int bits=0;
      for(int j=0;j<i;j++){
	bits+=(1<<j);
      }
      now=now|bits;
      now=now&(~(1<<i));
    }

    for(int j=0;j<n;j++){
      if((now|a[j])==now)sum+=b[j];
    }
    ans=max(ans,sum);
  }

  cout<<ans<<endl;
  return(0);
}
