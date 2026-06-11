#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,m;
  cin >> n>> m;
  ll ans=0;
  if(abs(n-m)>1){
    cout << 0;
    return 0;
  }
  ll p=1,q=1,r=1,mod=1e9+7;
  for(int i=1;i<=n;i++){
    p*=i;
    p%=mod;
  }
  for(int i=1;i<=m;i++){
    p*=i;
    p%=mod;
  }
  if((n+m)%2==0){
    p*=2;
    p%=mod;
  }
  cout << p;
  
}