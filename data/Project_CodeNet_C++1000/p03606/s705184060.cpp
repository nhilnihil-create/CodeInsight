#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,ans=0;
  cin >> n;
  vector<long> l(n),r(n);
  for(long i=0;i<n;i++) {
    cin >> l[i] >> r[i];
    ans+=r[i]-l[i]+1;
  }
  cout << ans << endl;
}