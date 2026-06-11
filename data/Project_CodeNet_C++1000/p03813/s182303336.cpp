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
  int x;
  cin >> x;

  if (x < 1200) cout << "ABC" << endl;
  else cout << "ARC" << endl;

  return 0;
}
