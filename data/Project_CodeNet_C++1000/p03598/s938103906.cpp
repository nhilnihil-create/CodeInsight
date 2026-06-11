#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, ans;
  cin >> n >> k;
  ans = 0;
  
  for (int i=0; i<n; i++) {
    int x;
    cin >> x;
    
    if (x < k-x)
      ans += x*2;
    else
      ans += (k-x)*2;
  }
  
  cout << ans << endl;
}
