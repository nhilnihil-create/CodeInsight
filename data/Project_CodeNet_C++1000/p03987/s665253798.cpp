#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,ans=0;
  cin >> n;
  vector<long> a(n);
  vector<long> b(n);
  for(long i=0;i<n;i++) cin >> a[i];
  for(long i=0;i<n;i++) b[a[i]-1]=i;
  set<long> aaa={-1,n};
  for(long i=0;i<n;i++) {
    auto itr=aaa.upper_bound(b[i]);
    long x=*itr-b[i];
    itr--;
    long y=b[i]-*itr;
    ans+=x*y*(i+1);
    aaa.insert(b[i]);
  }

  cout << ans << endl;
}