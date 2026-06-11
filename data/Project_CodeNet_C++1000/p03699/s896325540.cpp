#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
  ll n;
  cin>>n;
  ll s[n+4];
  rep(i,n){
    cin>>s[i];
  }
  ll ans=0;
  rep(i,n){
    ans+=s[i];
  }
  if(ans%10==0){
    sort(s,s+n);
    rep(i,n){
     if(s[i]%10!=0){
       ans-=s[i];
       break;
     }
    }
  }
  if(ans%10==0){
    cout<<'0'<<endl;
  }
  else{
    cout<<ans<<endl;
  }
       }