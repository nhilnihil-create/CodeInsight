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
  char op;
  cin >> A >> op >> B;

  if (op == '+') cout << A+B << endl;
  else cout << A-B << endl;

  return 0;
}
