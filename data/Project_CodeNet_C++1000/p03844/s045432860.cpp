#include <iostream>
using namespace std;
int main() {
  long a,b;
  string op;
  cin >> a >> op >> b;
  op == "-" ? cout << a - b : cout << a + b;
  return 0;
}