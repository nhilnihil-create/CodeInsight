#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,m=2,ans;
  cin >> n;
  vector<long> a(n);
  for(long i=0;i<n;i++) cin >> a[i];
  ans=a[0]-1;
  for(long i=1;i<n;i++) {
    if(a[i]==m) m++;
    else if(a[i]>m) ans+=(a[i]-1)/m;
  }
  cout << ans << endl;
}