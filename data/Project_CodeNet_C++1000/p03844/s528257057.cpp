#include <bits/stdc++.h>
using namespace std;
//A - Addition and Subtraction Easy
int main() {
  int a,b;
  char op;
  cin >> a >> op >> b;
  if(op=='+')
    cout << a + b << endl;
  else if (op=='-')
    cout << a - b << endl;
  else
    cout << "error" << endl;
}
