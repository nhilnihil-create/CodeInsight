#include <bits/stdc++.h>
using namespace std;
 
int main () {
  string S;
  cin >> S;
  bool ok = true;
  for (int i = S.size() - 2; i > 0; i -= 2) {
    for (int j = 0; j < i / 2; j++) {
      if (S.at(j) != S.at(j + i / 2)) {
        break;
      }
      else if (j == i / 2 - 1) {
        cout << i << endl;
        ok = false;
        break;
      }
    }
    if (ok == false) {
      break;
    }
  }
}
          