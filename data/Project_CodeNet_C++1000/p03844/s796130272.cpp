#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  int answer = 0;
  string op;
  cin >> A >> op >> B;
  
  if (op == "+") {
    answer = A + B;
  }
  if (op == "-") {
    answer = A - B;
  }
  
  cout << answer << endl;
 }