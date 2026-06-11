#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,a[200000],num[200000];
  cin >> n;
  
  for(int i = 0; i < 200000; i++)
    num[i] = 0;
  
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    num[a[i]]++;
  }

  int ans = 0, cnt;
  for(int i = 0; i < 110000; i++) {
    if(i == 0) 
      cnt = num[i] + num[i+1];
    else
      cnt = num[i-1] + num[i] + num[i+1];
    
    ans = max(ans, cnt);
  }

  cout << ans << endl;
  return 0;
}