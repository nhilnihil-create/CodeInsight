#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,a,b,ans=0;
  cin >> n >> a >> b;
  vector<long> x(n);
  for(long i=0;i<n;i++) cin >> x[i];

  for(long i=1;i<n;i++) {
    ans+=min(a*x[i]-a*x[i-1],b);
  }
  cout << ans << endl;
}