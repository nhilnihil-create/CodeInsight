#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int a, b;
  cin >> a >> b;
  if (a == 0 || b == 0 || (a < 0 && 0 < b)) {
    cout << "Zero" << endl;
    return 0;
  }
  if (0 < a && 0 < b) {
    cout << "Positive" << endl;
    return 0;
  }

  if (0 < b) {
    b = 0;
  }

  if ((abs(a) - abs(b) + 1) % 2) {
    cout << "Negative" << endl;
  } else {
    cout << "Positive" << endl;
  }
  return 0;
}
