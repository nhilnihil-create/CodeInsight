#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin >> H >> W;
  string A;
  
  for (int i = 0; i < (H + 2); i++){
    
    A = "";
    
    //1行目は#で埋める
    if (i == 0){
      for(int j = 0; j < (W + 2); j++){
        A = A + '#';
      }
    }
    //最終行は#で埋める
    else if (i == (H + 1)){
      for(int j = 0; j < (W + 2); j++){
        A = A + '#';
      }
    }
    //間の行は先頭と最後尾を#で埋める
    else{
      cin >> A;
      A = '#' + A + '#';
    }

    //出力
    cout << A << endl;
    
  }
}