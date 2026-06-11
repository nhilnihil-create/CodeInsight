#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ll n,m;cin>>n>>m;
  ll a[n];
  ll ko[m+1];
  ll ko2[m+1];
  ll wa[m+1];
  fill(ko,ko+m+1,0);
  fill(wa,wa+m+1,0);
  fill(ko2,ko2+m+1,0);
  for(ll i=0;i<n;i++){
    cin>>a[i];
    if(i<n-1){
      ko2[a[i]]++;
    }
    if(i>0){
      ko[a[i]]++;
    }
    if(i>0){
      wa[a[i]]+=(a[i]-a[i-1]+m)%m-1;
    }
  }
  ll ans[m+1];
  fill(ans,ans+m+1,0);
  ll cnt=0;
  for(ll i=1;i<n;i++){
    if(a[i]<a[i-1]){
      cnt++;
      ans[1]+=a[i];
    }
    else{
      ans[1]+=a[i]-a[i-1];
    }
  }
  for(ll i=2;i<=m;i++){
    //cout<<cnt<<endl;
    ans[i]=ans[i-1];
    ans[i]+=wa[i-1];
    cnt-=ko[i-1];
    ans[i]-=cnt;
    cnt+=ko2[i-1];
  }
  ll anss=ans[1];
  for(ll i=2;i<=m;i++)anss=min(anss,ans[i]);
  cout<<anss<<endl;
  //for(ll i=1;i<=m;i++)cout<<ans[i]<<" ";
}
        
      