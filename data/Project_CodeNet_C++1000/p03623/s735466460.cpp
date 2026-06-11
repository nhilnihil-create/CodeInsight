#include <bits/stdc++.h>
using namespace std;

int main() {
  int x , a , b , d , e;
  cin >> x >> a >> b;
  if ( x-a < 0) {
    d =a-x;
  }else d= x-a ;
  if (x-b < 0 ) {
    e = b-x ;
  }else e = x-b ;
  cout << (d < e ? 'A' : 'B') << endl;
}