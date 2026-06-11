#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  string op;
  cin >> A >> op >> B;
  char c = op.at(0);
  if (c=='+') {
    cout << A+B << endl;
  }
  else {
    cout << A-B << endl;
  }
}