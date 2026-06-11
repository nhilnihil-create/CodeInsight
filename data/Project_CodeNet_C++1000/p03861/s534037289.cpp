#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t a, b, t;
  cin >> a >> b >> t;
  
  int64_t x, y, ans;
  
  x = b / t;
  y = (a+(t-1))/t;
  
  ans = x-y+1;
  
  

  
  cout << ans << endl;

  
 
}
             