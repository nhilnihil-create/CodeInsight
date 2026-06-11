#include <bits/stdc++.h>
using namespace std;

int main() {
  string A, B, C;
  cin >> A; reverse(A.begin(),A.end());
  cin >> B; reverse(B.begin(),B.end());
  cin >> C; reverse(C.begin(),C.end());
  string win; //勝者
  char next = 'a';  //次の人、最初はA

  while(true){
  if (next == 'a'){
  //Aがカードを1枚捨てる
    if (A.size()>=1){
      next = A.at(A.size()-1);//次の人
      A.pop_back();
    }
    else {
      win = "A";
      break;
    }
  }
  else if (next == 'b'){
  //Bがカードを1枚捨てる
    if (B.size()>=1){
      next = B.at(B.size()-1);//次の人
      B.pop_back();
    }
    else {
      win = "B";
      break;
    }
  }
  //Cがカードを1枚捨てる
  else if (next == 'c'){
    if (C.size()>=1){
      next = C.at(C.size()-1);//次の人
      C.pop_back();
    }
    else {
      win = "C";
      break;
    }
  }
  }

  cout << win << endl;
}