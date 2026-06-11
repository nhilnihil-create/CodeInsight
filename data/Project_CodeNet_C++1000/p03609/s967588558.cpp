#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int X, t;
  cin >> X >> t;

  cout << std::max(0, X - t) << endl;

  return 0;
}
