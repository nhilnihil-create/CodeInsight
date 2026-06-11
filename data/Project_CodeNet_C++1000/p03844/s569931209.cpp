#include<bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  char op;
  int c = 0;
  cin >> a >> op >> b;
  if(op == '+') c = (a + b);
  else if(op == '-') c = (a - b);
  cout << c << endl;
}
