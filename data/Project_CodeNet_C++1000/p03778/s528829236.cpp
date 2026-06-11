#include <bits/stdc++.h>
using namespace std;

int main() {
  int W, a, b;
  cin >> W >> a >> b;
  
  if ( a + W < b ){
    cout << b - a- W ;
  }
  else if ( a - W <= b && b <= a + W ){
    cout << "0";
  }
  else if ( b + W < a ){
    cout << a - b - W;
  }
}