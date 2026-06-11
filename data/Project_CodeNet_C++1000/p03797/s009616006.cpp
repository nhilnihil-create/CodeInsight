#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t n, m;
  cin >> n >> m;
  
  int64_t ans;
  
  if(2*n < m){
    ans = n + (m - 2*n)/4;
  }
  
  else{
    ans = m / 2;
  }
  
  cout << ans << endl;

}
       