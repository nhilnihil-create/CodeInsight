#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;
  int rbra = 0; //)
  int lbra = 0;// (
  for(int i=0;i<N;i++){
    //0:(, 1:)
    if(S.at(i) - '('){ //)
      if(lbra){ //(が残っている
        lbra--; //(を減らす
      }else{ //(がない
        rbra++; //)を増やす
      }
    }else{ // (
      lbra++; // (を増やす
    }
  }
  string tmp = "";
  for(int i=0;i<rbra;i++){ //残りの)の数だけ(をくっつける
    tmp += "(";
  }
  S = tmp + S;
  
  lbra = 0;
  for(int i=0;i<S.size();i++){
    lbra += (S.at(i)-'(')*(-2) + 1;
  }
  tmp = "";
  for(int i=0;i<lbra;i++){ // (の数)をくっつける
    tmp += ")";
  }
  S = S + tmp;
  cout << S << endl;
  return 0;
}