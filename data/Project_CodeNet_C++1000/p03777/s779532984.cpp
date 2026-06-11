#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  char a, b;
  cin >> a >> b;
  if (a == 'H') {
    if (b == 'H')
      cout << "H\n";
    else
      cout << "D\n";
  }
  else {
    if (b == 'H')
      cout << "D\n";
    else
      cout << "H\n";
  }
  return 0;
}
