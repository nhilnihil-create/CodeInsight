#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c, d;
  int r1, r2;
  cin >> a >> b >> c >> d;
  
  r1 = a*b;
  r2 = c*d;
  
  cout << max(r1, r2);
  
  return 0;
}
