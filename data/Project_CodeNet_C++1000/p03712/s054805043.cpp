#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  string a, b(W + 2, '#');
  for (cout << b << endl; H; H--) {
    cin >> a;
    cout << '#' << a << '#' << endl;
  }
  cout << b;
}
