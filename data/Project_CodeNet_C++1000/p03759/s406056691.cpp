#include <bits/stdc++.h>
using namespace std;

int main() {
  int a[3];
  for ( int i=0; i<3; i++ ) cin >> a[i];
  for ( int i=0; i<3; i++ ) {
    for ( int j=0; j<3; j++ ) {
      for ( int k=0; k<3; k++ ) {
        if ( i!=j&&j!=k&&k!=i ) {
          if ( a[j]-a[i]==a[k]-a[j] ) {
            cout << "YES";
            return 0;
          }
        }
      }
    }
  }
  cout << "NO";
  return 0;
}
