#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, k, x, y;
  cin >> n >> k >> x >> y;
  int ans;
  if(n>k){
    ans = (k * x ) + ((n - k) * y);
    cout << ans << endl;
  }
  else{
    ans = n*x;
    cout << ans << endl;
  }
}
  