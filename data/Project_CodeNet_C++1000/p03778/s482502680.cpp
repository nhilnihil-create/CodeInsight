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
  int W, a, b;
  cin >> W >> a >> b;

  int d;
  if (a < b) {
    if (a + W >= b) d = 0;
    else d = b - (a + W);
  } else {
    if (b + W >= a) d = 0;
    else d = a - (b + W);
  }

  cout << d << endl;

  return 0;
}
