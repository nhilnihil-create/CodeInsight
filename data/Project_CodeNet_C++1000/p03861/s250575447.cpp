#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t a ;
  int64_t b ;
  int64_t c ;
  cin >> a >> b >> c ;
  if ( a ==0 )
    cout << b/c+1 << endl;
if ( a!=0) 
  cout << b/c - (a-1)/c << endl;
}
  