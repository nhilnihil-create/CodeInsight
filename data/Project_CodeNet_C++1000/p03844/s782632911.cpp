#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  string p;
  cin >> a >> p >> b;

  if (p == "+") {
    cout << a + b << endl;
  }
  
  else if (p == "-") {
    cout << a - b << endl;
  }
}
