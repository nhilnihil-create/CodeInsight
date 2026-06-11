#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,ans=0,mod=1000000007,x=0,ziyu=1;
  cin >> n;
  vector<long> xx(n+100);
  for(long i=0;i<n-1;i++) {
    xx[i+2]=ziyu;
    ans=(ans+ziyu*min(n-1,i+2))%mod;
    ans=(ans+(ziyu*(n-1))%mod*(n-1))%mod;
    x=(x+xx[i])%mod;
    ziyu=(ziyu+x)%mod;
  }
  ans=(ans+(ziyu*n))%mod;
  cout << ans << endl;
}