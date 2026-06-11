#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool b=false;
  while ( n ) {
    if ( n%10==9 ) b=true;
    n/=10;
  }
  if ( b ) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}
