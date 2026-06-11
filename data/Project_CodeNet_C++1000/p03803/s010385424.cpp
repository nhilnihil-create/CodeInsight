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

  if (A == 1) A += 13;
  if (B == 1) B += 13;

  if (A == B) cout << "Draw" << endl;
  else if (A < B) cout << "Bob" << endl;
  else cout << "Alice" << endl;

  return 0;
}
