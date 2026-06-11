#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  
  int lr[n][2];
  
  for(int i = 0; i < n; i++)
    cin >> lr[i][0] >> lr[i][1];
  
  int tmp;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    tmp = lr[i][1] - lr[i][0] + 1;
    ans += tmp;
  }
  
  cout << ans;
}