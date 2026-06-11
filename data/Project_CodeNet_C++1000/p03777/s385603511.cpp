#include <bits/stdc++.h>
using namespace std;

int main() {
  string a,b;
  cin >> a >> b;
  if ( a=="H") {
    cout << b << '\n';
  } else {
    cout << ( b=="H" ? "D" : "H" ) << '\n';
  }
  return 0;
}