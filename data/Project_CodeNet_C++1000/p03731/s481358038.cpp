#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
 
int main() {
  //input
  int n; cin >> n;
  long T; cin >> T;
  long sum;
  long ans;
  sum = 0;
  ans = 0;
  vector<long> t(n);
  for(int i = 0; i < n; i++)  cin >> t[i];
  
  //compute
  for(int i = 0; i < n - 1; i++) {
    if(t[i + 1] > t[i] + T){
          sum += t[i + 1] - t[i] - T;
      }
  }

  ans = t[n -1] + T - sum;

  //output
  cout << ans << endl;
 
}