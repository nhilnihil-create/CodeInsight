#include <bits/stdc++.h>
using namespace std;

int main() {
	
  //初期宣言と型の設定
  int A, B, C;
  string op;
  
  //入力部
  cin >> A >> op >> B;
  
  if(op=="+"){
    C=A+B;
  }
  else if(op=="-"){
    C=A-B;
  }
  else{
    cout <<"error"<< endl;
  }
  cout << C << endl;
}
