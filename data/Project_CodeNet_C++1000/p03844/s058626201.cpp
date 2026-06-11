#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A;
  cin >> A;
  char op;
  cin >> op;
  int B;
  cin >> B;
  if (op == '+') {
    cout << A + B << endl;
  }
  else { cout << A - B << endl;}
}