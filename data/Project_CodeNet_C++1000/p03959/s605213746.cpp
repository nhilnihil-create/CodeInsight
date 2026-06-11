#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000000007;
int main(){
  ll n;
  cin >> n;
  vector<ll> t(n),a(n),h(n);
  for(int i=0;i<n;i++){
    cin >> t[i];
  }
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  ll ans=1;
  h[0]=1;
  h[n-1]=1;
  for(int i=1;i<n-1;i++){
    if(t[i-1]==t[i]){
      if(a[i]==a[i+1]){
        h[i]=min(t[i],a[i]);
      }
      else{
        if(t[i]>=a[i]){
          h[i]=1;
        }
        else{
          h[i]=0;
        }
      }
    }
    else{
      if(a[i]==a[i+1]){
        if(t[i]<=a[i]){
          h[i]=1;
        }
        else{
          h[i]=0;
        }
      }
      else{
        if(t[i]==a[i]){
          h[i]=1;
        }
        else{
          h[i]=0;
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    ans*=h[i];
    ans%=mod;
  }
  if(t[n-1]!=a[0]){
    ans=0;
  }
  cout << ans << endl;
}
