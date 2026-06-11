#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string op;
  int A,B;
  cin >> A >> op >> B;
  int result;
  
  if (op == "+"){
    result = A + B;
  }
  else if(op == "-"){
    result = A - B;
  }
  
  cout << result << endl;
}
 