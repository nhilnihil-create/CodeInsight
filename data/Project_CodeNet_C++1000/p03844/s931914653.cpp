#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,ans;
  char op;
  
  ans = 0;
  
  cin >> A >> op >> B;
  
  switch(op){
    case '+':
        ans = A + B;
        break;
    case '-':
        ans = A - B;
        break;
    default:
        break;
  }
  
  cout << ans << endl;
  return 0;
}