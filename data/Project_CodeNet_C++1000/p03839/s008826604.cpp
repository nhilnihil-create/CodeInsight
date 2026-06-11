#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll s[100009];
ll t[100009];

int main(){
  int n,k;
  int a[100009];
  cin>>n>>k;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    s[i]=s[i-1]+a[i];
    t[i]=t[i-1]+max(a[i],0);
  }

  ll ans=s[n];
  for(int i=1;i<=n-k+1;i++){
    ans=max(ans,t[i-1]+(s[i+k-1]-s[i-1])+t[n]-t[i+k-1]);
    ans=max(ans,t[i-1]+t[n]-t[i+k-1]);
  }
  
  cout<<ans<<endl;
  return(0);
}
