#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int c=0,d=0;
  bool b[8]={};
  for ( int i=0; i<n; i++ ) {
    int a;
    cin >> a;
    if ( a>=3200 ) c++;
    else {
        b[a/400]=1;
    }
  }
  for ( int i=0; i<8; i++ ) {
    if ( b[i] ) d++;
  }
  cout << max(1,d) << ' ' << d+c << '\n';
  return 0; 
}
