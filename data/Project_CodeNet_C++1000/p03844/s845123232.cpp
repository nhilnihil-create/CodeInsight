#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string A, op, B;
  cin >> A >> op >> B;
  
  int a = stoi(A);
  int b = stoi(B);
  int ans = 0;
  
  if(op == "+"){
    ans = a + b;
  }
  if (op == "-"){
    ans = a - b;
  }
  
  cout << ans << endl;

}
     