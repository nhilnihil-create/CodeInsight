#include <bits/stdc++.h>
using namespace std;
 

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  
  int res = 0;
  if (a == b && b == c) {
    res = 1;
  } else if (a == b || b == c || c == a) {
    res = 2;
  } else {
    res = 3;
  }
    
  cout << res << endl;
  return 0;
}