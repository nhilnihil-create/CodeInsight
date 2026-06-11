#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  string a, b;
  cin >> H >> W;
  for (; W > -2; W--) b += '#';
  for (cout << b << endl; H; H--) {
    cin >> a;
    cout << '#' << a << '#' << endl;
  }
  cout << b;
}