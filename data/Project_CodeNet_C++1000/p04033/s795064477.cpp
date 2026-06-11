#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t a, b;
  cin >> a >> b;
  
  if (a <= 0 && 0 <= b) {
    cout << "Zero" << endl;
  }
  else if (a > 0) {
    cout << "Positive" << endl;
  }
  else if (b > 0) {
    if (abs(a) % 2 == 0) {
      cout << "Positive" << endl;
    }
    else {
      cout << "Negative" << endl;
    }
  }
  else {
    if ((abs(a) - abs(b)) % 2 != 0) {
      cout << "Positive" << endl;
    }
    else {
      cout << "Negative" << endl;
    }
  }
}
