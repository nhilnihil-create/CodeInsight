#include <bits/stdc++.h>
using namespace std;

// -------------------
// ここから先は変更しない
// -------------------
int main() {
  string name;
  int A,B;
  int num = 0;
  cin >> A >> name >> B;
  if(name=="+"){
    num = A+B;
  }else if(name =="-"){
    num = A-B;
  }
  cout << num << endl;
}
