#include <bits/stdc++.h>
using namespace std;

int main() {
  string a,b;
  cin >> a >> b;
  string ans="";
  int al=a.size(),bl=b.size();
  int n=al+bl;
  int ai=0,bi=0;
  for ( int i=1; i<=n; i++ ) {
    if ( i%2 ) {
      ans+=a[ai++];
    } else{
      ans+=b[bi++];
    }
  }
  cout << ans << '\n';
  return 0; 
}