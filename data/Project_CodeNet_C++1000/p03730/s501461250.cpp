#include <iostream>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  bool ok = false;
  for (int i = a; i <= b * a; i++) {
    if (i % a == 0 && i % b == c) {
      ok = true;
      break;
    }
  }
  if (ok) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
