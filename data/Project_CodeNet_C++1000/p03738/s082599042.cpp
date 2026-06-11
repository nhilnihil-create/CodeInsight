#include <iostream>
#include <string>

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  size_t as = a.size();
  size_t bs = b.size();

  if (as > bs) {
    cout << "GREATER" << endl;
  } else if (as < bs) {
    cout << "LESS" << endl;
  } else {
    bool eq = true;
    for (int i = 0; i < as; i++) {
      if (a[i] > b[i]) {
        cout << "GREATER" << endl;
        eq = false;
        break;
      } else if (b[i] > a[i]) {
        cout << "LESS" << endl;
        eq = false;
        break;
      }
    }
    if (eq) {
      cout << "EQUAL" << endl;
    }
  }
  return 0;
}
