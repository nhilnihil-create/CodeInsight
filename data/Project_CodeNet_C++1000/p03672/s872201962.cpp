#include <bits/stdc++.h>
using namespace std;

int main() {
  string S; 
  cin >> S;
  
  int n = S.size();
  int ans = 2;
  // i文字＊２になっているか？をチェックしていく
  for (int i = 0; i < n/2; i++) {
    bool cond = true;
    for (int j = 0; j < i; j++) {
      if (S[j] != S[j+i]) {
        cond = false;
        break;
      }
    }
    if (cond) ans = 2 * i;
  }
  
  cout << ans << endl;
}