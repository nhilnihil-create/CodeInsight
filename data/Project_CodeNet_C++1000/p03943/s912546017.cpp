#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (max(max(a, b), c) * 2 == a + b + c) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
