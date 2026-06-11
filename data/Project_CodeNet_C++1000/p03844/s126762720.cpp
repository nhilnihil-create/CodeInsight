#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  string op;
  cin >> A >> op >> B;
  
  if (op == "+") {
    A += B;
  }
  else if (op == "-") {
    A -= B;
  }
  
  cout << A << endl;
  
}