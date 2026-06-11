#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  char op;
  cin >> a >> op >> b;
  
  if(op == '+') a += b;
  else a -= b;
  
  cout << a << endl;
}
