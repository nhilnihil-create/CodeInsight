#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  int x = 0;
  int y = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == 'A') {
      x = i;
      break;
    }
  }
  for (int i = a.size(); i >= 0; i--) {
    if (a[i] == 'Z') {
      y = i;
      break;
    }
  }
  cout << y-x+1 << endl;
}