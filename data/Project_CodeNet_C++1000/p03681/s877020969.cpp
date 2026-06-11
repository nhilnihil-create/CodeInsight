#include <bits/stdc++.h>
using namespace std;
using ll=long long;
typedef pair<int,int>P;
 
int main() {
  ll a,b,small,large,ans,modint;
  cin>>a>>b;
  small=min(a,b);
  large=max(a,b);
  modint=1000000007;
  if(large-small>=2){
    cout<<0<<endl;
  }
  else{
    if(a==b){
      ans=2;
      for(ll i=a;i>0;i--){
        ans*=i;
        if(ans>=modint){
          ans%=modint;
        }
        ans*=i;
        if(ans>=modint){
          ans%=modint;
        }
      }
      cout<<ans<<endl;
    }
    else{
      ans=large;
      for(ll j=small;j>0;j--){
        ans*=j;
        if(ans>=modint){
          ans%=modint;
        }
         ans*=j;
        if(ans>=modint){
          ans%=modint;
        }
      }
      cout<<ans<<endl;
    }
  }
}