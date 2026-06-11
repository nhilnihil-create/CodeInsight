#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  for ( int k=1; k<=100; k++ ) {
    if ( a*k%b==c ) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0; 
}