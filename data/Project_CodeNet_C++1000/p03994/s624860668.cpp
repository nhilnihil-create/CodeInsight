#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  int K;
  cin >> K;
  
  for (int i = 0; i < S.size(); i++) {
    if (K < 26 - (S[i] - 'a')) {
      if (i < S.size()-1) {
        continue;
      } else {
        // 最後の文字を出来る限り回す
        // aに戻らないことが確定しているので単に足すだけでオッケー
        S[i] = S[i] + K;
        K = 0;
        break;
      }
    } else {
      
      if (S[i] == 'a') continue;
      
      // その文字を'a'になるまで動かす
      K -= 26 - (S[i] - 'a');
      S[i] = 'a';
    }
    
  }
  
  if (K > 0) {
    K %= 26;
    
    
    S[S.size()-1] = S[S.size()-1] + K;
  }
  
  
  cout << S << endl;

}