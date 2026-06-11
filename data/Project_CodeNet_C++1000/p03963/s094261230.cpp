#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, k;
  cin >> n >> k;
  
  int ans = k;
  if (n > 1) {
    for (int i = 2; i <= n; i++) {
      ans *= k-1;
    }
  }
  
  cout << ans << endl;
    
}