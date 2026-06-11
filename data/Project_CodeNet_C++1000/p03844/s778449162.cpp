#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,ans;
  string op;
  cin >> A >> op >> B;
  if(op.at(0) == '+'){
    ans = A + B;
  }else if (op.at(0) == '-'){
    ans = A - B;
  }
  cout << ans << endl;

}