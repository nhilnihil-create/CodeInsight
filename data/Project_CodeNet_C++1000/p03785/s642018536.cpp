#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,c,k,t[200000];
  cin >> n >> c >> k;
  for(int i = 0; i < n; i++)
    cin >> t[i];
  
  if(c == 1) {
    cout << n << endl;
    return 0;
  }

  sort(t,t+n);

  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(i == n-1) {
      cnt++;
      break;
    }
    for(int j = i+1; j < n; j++) {
      if(t[i]+k < t[j]) {
        cnt++; i = j-1;
        break;
      }
      else {
        if(j-i+1 <= c) continue;
        else {
          cnt++; i = j-1;
          break;
        }
      }
    }
  }
  cout << cnt << endl;
  return 0;
}