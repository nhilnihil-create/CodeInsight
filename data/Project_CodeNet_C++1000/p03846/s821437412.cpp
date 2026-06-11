#include <bits/stdc++.h>
using namespace std;
long mod=1000000007;
long modpow(long modpow_x,long modpow_y) {
  long modpow_return=1;
  for(long i=1;i<=modpow_y;i*=2) {
    if(modpow_y/i%2==1) modpow_return=modpow_return*modpow_x%mod;
    modpow_x=modpow_x*modpow_x%mod;
  }
  return modpow_return;
}
int main() {
  long n;
  bool o=true;
  cin >> n;
  vector<long> a(n);
  vector<long> b(n);
  for(long i=0;i<n;i++) cin >> a[i];

  for(long i=0;i<n;i++) b[a[i]]++;
  for(long i=0;i<n;i++) {
    if(i%2==0&&n%2==1) {
      if(i==0&&b[i]!=1) o=false;
      if(i!=0&&b[i]!=2) o=false;
    } else if(i%2==1&&n%2==0) {
      if(b[i]!=2) o=false;
    } else {
      if(b[i]!=0) o=false;
    }
  }

  if(o) cout << modpow(2,n/2) << endl;
  else cout << 0 << endl;
}