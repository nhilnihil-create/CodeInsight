#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, a, b;
  cin >> x >>  a >> b;
 
  int xa ,xb;
  
  if ( x > a ){
    xa = (x - a);
  }
  else {
    xa = (a - x);
  }
  
  if ( x > b ){
    xb = (x - b);
  }
  else {
    xb = (b - x);
  }
  
  
  if ( xa > xb ){
    cout << "B" <<endl;
  }
  else {
    cout << "A" <<endl;
  }
}
