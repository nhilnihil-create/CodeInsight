#include <bits/stdc++.h>
using namespace std;
long n,ans=1,mod=1000000007;
long modpow(long modpow_x,long modpow_y) {
  long modpow_return=1;
  for(long i=1;i<=modpow_y;i*=2) {
    if(modpow_y/i%2==1) modpow_return=modpow_return*modpow_x%mod;
    modpow_x=modpow_x*modpow_x%mod;
  }
  return modpow_return;
}
int main() {
  cin >> n;
  map<long,long> a;
  for(long i=2;i<=n;i++) {
    long aaa=i;
    for(long j=2;j<=1200;j++) {
      while(aaa%j==0) {
        a[j]++;
        aaa/=j;
      }
    }
  }
  for(auto itr=a.begin();itr!=a.end();itr++) {
    ans=(ans*(((*itr).second)+1))%mod;
  }
  cout << ans << endl;
}