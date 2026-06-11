#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1.0);

int main() {
  int a, b;
  cin >> a >> b;
  if (a == 1 && b == 1) {
    cout << "Draw" << endl;
  } else if (a == 1) {
    cout << "Alice" << endl;
  } else if (b == 1) {
    cout << "Bob" << endl;
  } else {
    if (a == b)
      cout << "Draw" << endl;
    else if (a > b)
      cout << "Alice" << endl;
    else
      cout << "Bob" << endl;
  }
}