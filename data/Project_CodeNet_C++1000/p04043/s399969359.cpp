#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == 5) {
    if ((b == 5 && c == 7) || (b == 7 & c == 5)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else if (a == 7) {
    if ((b == 5 && c == 5)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    cout << "NO" << endl;
  }
}