#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  if (a == 1) {
    if (b == 1)
      cout << "Draw\n";
    else
      cout << "Alice\n";
  }
  else if (b == 1) {
    cout << "Bob\n";
  }
  else {
    cout << ((a > b) ? "Alice" : (a < b) ? "Bob" : "Draw") << "\n";
  }
  return 0;
}
