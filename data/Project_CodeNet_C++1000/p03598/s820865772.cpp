#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
  // input
  int n,k; cin >> n >> k;
  vector<int> x(n);
  vector<int> m(n);
  for(int i = 0;i < n; i++) cin >> x[i]; 
  

  // compute
  int ans = 0;
  for(int i = 0;i < n; i++) m[i] = min(x[i],k-x[i]);
  for(int i = 0;i < n; i++) ans += (2 * m[i]);
 
  // output  
  cout << ans << endl;
  
}