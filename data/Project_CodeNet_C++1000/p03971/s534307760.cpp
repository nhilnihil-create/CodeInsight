#include <iostream>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int ja = 0, ov = 0;
  char c;
  while (n--) {
    cin >> c;
    if (c == 'a') {
      if (ja + ov < a + b) {
        cout << "Yes\n";
        ++ja;
      } else {
        cout << "No\n";
      }
    } else if (c == 'b') {
      if (ja + ov < a + b && ov < b) {
        cout << "Yes\n";
        ++ov;
      } else {
        cout << "No\n";
      }
    } else {
      cout << "No\n";
    }
  }
  return 0;
}
