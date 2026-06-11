#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const ll MOD=1e9+7;

int main(){
  ll n,m;
  cin>>n>>m;
  ll ans;
  if(abs(n-m)>1){
    ans=0;
  }else{
    ll p=1, q=1;
    for(int i=1; i<=n; i++){
      p*=i; 
      p%=MOD;
    }
    for(int i=1; i<=m; i++){
      q*=i; 
      q%=MOD;
    }
    ans=p*q%MOD;
    if(n==m) ans*=2;
  }
  ans%=MOD;
  cout<<ans<<endl;
}

