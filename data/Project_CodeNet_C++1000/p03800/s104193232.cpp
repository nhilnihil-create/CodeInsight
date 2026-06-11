#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
typedef long long ll;

int main(){
  int N; cin >> N;
  string S; cin >> S;
  S = S[N - 1] + S + S[0];

  int ans[N + 2][4];

  for (int i = 0; i < N + 2; i++){
    for (int j = 0; j < 4; j++){
      ans[i][j] = false;
    }
  }
  
  ans[1][0] = 1; ans[2][0] = 1;
  ans[1][1] = 1; ans[2][1] = 0;
  ans[1][2] = 0; ans[2][2] = 1;
  ans[1][3] = 0; ans[2][3] = 0;

  for (int j = 0; j < 4; j++){
    if (S[1] == 'o'){
      if (ans[1][j] == 1){
        ans[0][j] = ans[2][j];
      }else{
        ans[0][j] = 1 - ans[2][j];
      }
    }else{
      if (ans[1][j] == 1){
        ans[0][j] = 1 - ans[2][j];
      }else{
        ans[0][j] = ans[2][j];
      }
    }
  }
  

  for (int i = 2; i < N + 1; i++){
    for (int j = 0; j < 4; j++){
      if (S[i] == 'o'){
        if (ans[i][j] == 1){
          ans[i + 1][j] = ans[i - 1][j];
        }else{
          ans[i + 1][j] = 1 - ans[i - 1][j];
        }
      }else{
        if (ans[i][j] == 1){
          ans[i + 1][j] = 1 - ans[i - 1][j];
        }else{
          ans[i + 1][j] = ans[i - 1][j];
        }
      }
    }
  }

  bool flag = false;
  for (int j = 0; j < 4; j++){
    if (ans[0][j] == ans[N][j] && ans[1][j] == ans[N+1][j]){
      flag = true;
      for (int i = 1; i <= N; i++){
        if (ans[i][j] == 1){
          cout << "S";
        }else{
          cout << "W";
        }
      }
      cout << endl;
      break;
    } 
  }
  
  if (flag == false){
    cout << -1 << endl;
  }
  
  

  return 0;
}
