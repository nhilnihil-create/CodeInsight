#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,k;cin>>n>>k;
  ll a[n];
  ll sum[n+1];
  sum[0]=0;
  for(ll i=0;i<n;i++){
    cin>>a[i];
    sum[i+1]=sum[i]+a[i];
  }
  ll ys[n+1];
  ys[0]=0;
  for(ll i=0;i<n;i++){
    if(a[i]>0){
      ys[i+1]=ys[i]+a[i];
    }
    else ys[i+1]=ys[i];
  }
  ll ans=0;
  for(ll i=0;i<n-k+1;i++){
    ll ss=ys[n]-ys[i+k]+ys[i]-ys[0];
    ll kk=max(sum[i+k]-sum[i],(ll)0);
    ans=max(ans,ss+kk);
  }
  cout<<ans<<endl;
}