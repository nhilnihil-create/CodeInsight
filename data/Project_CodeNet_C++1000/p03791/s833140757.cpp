#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,ans=1,mod=1000000007,a=1;
  cin >> n;
  vector<long> x(n);
  for(long i=0;i<n;i++) cin >> x[i];
  for(long i=0;i<n;i++) {
    while(a!=n) {
      if(x[a-1]>=(a-i)*2-1&&x[a]>=(a-i)*2) a++;
      else break;
    }
    ans=ans*(a-i)%mod;
    a--;
  }
  cout << ans << endl;
}