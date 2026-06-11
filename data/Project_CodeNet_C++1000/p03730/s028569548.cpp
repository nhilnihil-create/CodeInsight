#include <iostream>

using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  bool pred = false;
  int x{A};
  for (auto i = B; i; --i) {
    x %= B;
    if (x == C) pred = true;
    x += A;
  }

  cout << (pred ? "YES" : "NO") << endl;

  return 0;
}
