#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll keta(ll n){
  ll i,ans=0;
  while(n>0){
    n/=10;
    ans++;
  }
  return ans;
}
int main(){
  ll n;
  cin >> n;
  ll i,cp=n,ans=1000;
  for(i=1;i*i<=n;i++){
    if(cp%i==0){
      ll q=cp/i;
      ll a=keta(q);
      ll b=keta(i);
      ll maxi=max(a,b);
      ans=min(ans,maxi);
    }
  }
  cout << ans;
}
  