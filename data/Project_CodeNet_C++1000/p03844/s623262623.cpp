#include <bits/stdc++.h>
using namespace std;

int main() {
  int l, r;
  char op;
  
  cin >> l >> op >> r;
  
  if (op == '+') {
    cout << (l + r) << endl;
  } else {
    cout << (l - r) << endl;
  }
}