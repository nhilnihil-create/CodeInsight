#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, b = 0;
  string a;
  cin >> H >> W;
  for (; b < W + 2; b++) cout << '#';
  for (cout << endl; H; H--) {
    cin >> a;
    cout << '#' << a << '#' << endl;
  }
  for (; b; b--) cout << '#';
}