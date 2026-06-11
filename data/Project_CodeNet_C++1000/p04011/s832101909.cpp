#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;

int main() {
  
  int n, k, x, y;
  cin >> n >> k >> x >> y;
  
  int ans = min(n,k)*x;
  
  if (n > k) ans += (n-k)*y;
  
  cout << ans << endl;

}