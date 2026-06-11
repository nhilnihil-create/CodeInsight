#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
  // input
  int n;cin >> n;
  vector<int> a(n);
  vector<int> x(n);
  
  for(int i = 0;i < n; i++) {
        cin >> a[i];
  }

  x[0]= 1;
  

  // compute 
  int ans = -1;
  for(int i = 0;i < n; i++) {
        x[i + 1] = a[x[i] - 1];
      if(x[i + 1] == 2){
          ans = i + 1;
          break;
      }
  }
 

  
  // output  
  cout << ans << endl;
  
}