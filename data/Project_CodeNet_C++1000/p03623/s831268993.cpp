#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,c;
  cin >> a >> b >> c;
  b = b-a;
  c = c-a;
  if (b < 0) {
    b *= -1;
  }
  if (c < 0) {
    c *= -1;
  }
  if (c > b) {
    cout << "A" << endl;
  } else {
    cout << "B" << endl;
  }
}