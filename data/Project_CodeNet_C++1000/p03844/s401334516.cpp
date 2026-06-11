#include <bits/stdc++.h>
using namespace std;
// Addition and Subtraction Easy
int main() {
  int a, b, x;
  char c;
  cin >> a >> c >> b;

  if (c == '+') {
    x = a + b;
  } else if (c == '-') {
    x = a - b;
  }

  cout << x << endl;
}