#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,ans = 1;
  cin >> n;

  int ma = 0;
  for(int i = 1; i <= n; i++) {
    int cnt = 0;
    int t = i;
    for(int j = 0; j < n; j++) {
      if(t % 2 == 0) {
        cnt++;
        t /= 2;
      }
      else break;
    }
    if(ma < cnt) {
      ma = cnt;
      ans = i;
    }
  }
  cout << ans << endl;
}