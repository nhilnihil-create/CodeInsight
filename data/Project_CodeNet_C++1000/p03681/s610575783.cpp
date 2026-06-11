#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main() {
  ll n,m;
  cin >>n >>m;
  ll ans=1;
  if(abs(n-m)>=2){cout << 0 << endl; return 0;}
  for(int i=1;i<=n;i++){
    ans=ans*i%mod;
  }
    for(int i=1;i<=m;i++){
    ans=ans*i%mod;
  }
  if(n==m)ans=ans*2%mod;
  cout << ans << endl;
}