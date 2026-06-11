#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
 
int main() {
  //input
  int n;cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  int counter = 0;
  
  //compute
  for(int i = 0; i < n; i++) a[i] = a[i] - 1;
  for(int i = 0;i < n; i++) {
         if(a[a[i]] == i){
           counter += 1;
         }
  }
  int ans;
  ans = counter / 2;
 
  //output
  cout << ans << endl;
  
}