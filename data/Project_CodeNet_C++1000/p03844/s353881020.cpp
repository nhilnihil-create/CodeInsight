#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  string op;
  cin >> a >> op >> b;
  int result = 0;
  if(op == "+"){
    result = a + b;
  }
  else{
    result = a - b;
  }
  cout << result;
}
