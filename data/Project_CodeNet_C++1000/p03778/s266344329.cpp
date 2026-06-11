#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t w, a, b;
  cin >> w >> a >> b;
  
  int64_t ans = 0;
  
  if(a > b){
    if(a+w-b > 2*w){
      ans = a - (b+w);
    }
    else{
      ans = 0;
    }
  }
  
  else if(a < b){
    if(b+w-a > 2*w){
      ans = b - (a+w);
    }
    else{
      ans = 0;
    }
  }
  
  cout << ans << endl;

}
            