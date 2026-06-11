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
  int x, a, b;
  cin >> x >> a >> b;

  if (std::abs(a-x) < std::abs(b-x)) cout << "A" << endl;
  else cout << "B" << endl;

  return 0;
}
