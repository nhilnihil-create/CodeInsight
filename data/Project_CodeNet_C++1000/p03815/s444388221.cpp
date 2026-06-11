#include <bits/stdc++.h>
using namespace std;

int main() {
  long int x, y;
  cin >> x;
  
  y = x/11;
  
  if ( x%11 == 0 ) {
   cout << y*2 << endl;
  }
  else if ( x%11 == 1 || x%11 == 2 || x%11 == 3 || x%11 == 4 || x%11 == 5 || x%11 == 6 ) {
    cout << y*2 + 1 << endl;
  }
  else {
    cout << y*2 + 2 << endl;
  }
     
}
