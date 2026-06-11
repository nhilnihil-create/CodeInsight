#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  string op;
  cin >> A >> op >> B;
  if (op[0]=='+'){
    cout << A+B << endl;
  }
  else {
    cout << A-B << endl;
  }
}
