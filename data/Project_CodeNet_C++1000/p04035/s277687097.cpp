#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,l,x=-1;
  cin >> n >> l;
  vector<long> a(n);
  for(long i=0;i<n;i++) cin >> a[i];
  for(long i=1;i<n;i++) if(a[i-1]+a[i]>=l) x=i;
  if(x==-1) cout << "Impossible" << endl;
  else {
    cout << "Possible" << endl;
    for(long i=n-1;i>x;i--) cout << i << endl;
    for(long i=1;i<=x;i++) cout << i << endl;
  }
}