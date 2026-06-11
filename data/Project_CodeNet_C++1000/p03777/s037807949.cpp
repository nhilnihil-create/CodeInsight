#include <iostream>
using namespace std;

int main() {
  char a, b;
  cin >> a >> b;
  if (a == 'H') cout << b << '\n';
  else {
    if (b == 'H') cout << "D\n";
    else cout << "H\n";
  }
  return 0;
}