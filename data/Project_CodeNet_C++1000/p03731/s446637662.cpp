#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,t,ans;
  cin >> n >> t;
  ans=t;
  vector<long> vect(n);
  for(long i=0;i<n;i++) cin >> vect[i];
  for(long i=1;i<n;i++) {
    ans+=min(vect[i]-vect[i-1],t);
  }
  cout << ans << endl;
}