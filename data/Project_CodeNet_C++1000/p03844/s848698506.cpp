#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, x;
  char op;
  cin >> A >> op >> B;
  if(op == '+')
    x = A + B;
  else
    x = A - B;
  cout << x << endl;
}