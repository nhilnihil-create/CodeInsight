#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  long long ans=1;
  if(abs(n-m)>=2) {
    cout << 0 << endl;
    return 0;
  }
  if(n-m==0) {
    ans*=2;
  }
  for(int i=1; i<=max(n,m); i++) {
    ans*=i;
    ans%=1000000007;
  }
  for(int i=1; i<=min(n,m); i++) {
    ans*=i;
    ans%=1000000007;
  }
  cout << ans << endl;
}