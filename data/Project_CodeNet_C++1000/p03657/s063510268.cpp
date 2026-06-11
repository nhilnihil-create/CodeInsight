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
  int A, B;
  cin >> A >> B;

  if (A % 3 == 0 || B % 3 == 0 || (A + B) % 3 == 0) cout << "Possible" << endl;
  else cout << "Impossible" << endl;

  return 0;
}
