#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  ll n,m,ans=1; cin >>n >>m;
  const ll M = 1e9 + 7;
  if(abs(n-m)>1){
    cout << 0 << endl;
    return 0;
  }
  if(n==m) ans*=2;
  for(ll i = 1; i<=n; i++) ans=ans*i%M;
  for(ll i = 1; i<=m; i++) ans=ans*i%M;
  cout << ans << endl;
  return 0;
}