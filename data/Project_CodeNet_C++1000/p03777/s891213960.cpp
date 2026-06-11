#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  char a, b;
  cin >> a >> b;

  if ((a == 'H' && b == 'H') || a == 'D' && b == 'D') cout << "H" << endl;
  else cout << "D" << endl;

  return 0;
}
