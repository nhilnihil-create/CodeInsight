#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;

int main(){
  ll n,i,j;
  cin >> n;
  ll a[n],t[n];
  for(i=0;i<n;i++){
    cin >> a[i];
  }
  for(i=0;i<n;i++){
    cin >> t[i];
  }
  ll m=0,ret[2][n];
  for(i=0;i<n;i++){
    if(a[i]>m){
      ret[0][i]=a[i];
      m=a[i];
    }else ret[0][i]=0;
  }

  m=0;
  for(i=n-1;i>=0;i--){
    if(t[i]>m){
      ret[1][i]=t[i];
      m=t[i];
    }else ret[1][i]=0;
  }
  ll ans=1;
  for(i=0;i<n;i++){
    if(ret[0][i]+ret[1][i]==0){
      ans*=min(a[i],t[i]);
      ans%=(ll)(1e9 +7);
    }else if(ret[0][i]!=0&&ret[1][i]!=0 && ret[0][i]!=ret[1][i]){
      ans=0;
    }else if(ret[0][i]==0){
      if(a[i]<ret[1][i])ans=0;
    }else if(ret[1][i]==0){
      if(t[i]<ret[0][i])ans=0;
    }
  }
  cout << ans << endl;
  return 0;
}
