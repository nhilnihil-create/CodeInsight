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
  int X, A, B;
  cin >> X >> A >> B;

  if (A >= B) cout << "delicious" << endl;
  else if (B - A <= X) cout << "safe" << endl;
  else cout << "dangerous" << endl;

  return 0;
}
