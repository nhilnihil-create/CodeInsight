#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  char op;
  cin >> x >> op >> y;
  
  int result;
  if(op == '+') {
    result = x + y;
  }
  else {
   	result = x - y; 
  }
  
  cout << result << endl;
}
