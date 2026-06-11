#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
  // input
  int n; cin >> n;
  vector<int> x(8);


  // compute
  int ans;
  for(int i = 0;i < 8; i++) x[i] = pow(2,i); 
  
  if(n == 1) ans = 1;

  for(int i = 1;i < 8; i++){
    if(n < x[i]){
        ans = x[i-1];
        break;
    }
  }
  
  // output  
  cout << ans << endl;
  
}