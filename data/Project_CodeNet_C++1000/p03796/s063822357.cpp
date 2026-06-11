#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=1,mod=1000000007;
  cin >> n;
  for(long i=1;i<=n;i++) ans=ans*i%mod;
  cout << ans << endl;
}