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
  int a, b, c;
  cin >> a >> b >> c;

  if (a + b == c || b + c == a || c + a == b) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
