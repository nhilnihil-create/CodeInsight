#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  double a, b;
  char op;

  cin >> a >> op >> b;
  
  int x;
  if ( op == '+' ) {
    x = a + b;
  } else {  // op == '-'
    x = a - b;
  }
  
  cout << x << endl;
}