#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >>n;
  
  int a[n], b[n];
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i];
  
  sort(a, a+n);
  sort(b, b+n);
  
  int ans = 0;
  ans += a[n-1] + b[0];
  
  cout << ans << endl;
}