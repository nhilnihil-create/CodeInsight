#include <iostream>

using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  char c;
  int cnt_a = 0;
  int cnt_b = 0;
  while (cin >> c) {
    if (c == 'a') {
      if (cnt_a + cnt_b < a + b) {
        cout << "Yes" << endl;
        ++cnt_a;
      } else {
        cout << "No" << endl;
      }
    } else if (c == 'b') {
      if ((cnt_a + cnt_b < a + b) && (cnt_b < b)) {
        cout << "Yes" << endl;
      ++cnt_b;
      }
      else {
        cout << "No" << endl;
      }
    } else {
      cout << "No" << endl;
    }
  }
}
