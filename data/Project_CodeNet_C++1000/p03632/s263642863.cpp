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
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  int mn = std::max(A, C);
  int mx = std::min(B, D);
  cout << std::max(mx - mn, 0) << endl;

  return 0;
}
