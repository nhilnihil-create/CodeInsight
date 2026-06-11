#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, a, b;
  string s;
  cin >> n >> a >> b;
  cin >> s;

  int nb = 0;
  int nab = 0;
  for (const char &c : s) {
    if (c == 'a') {
      if (nab < a + b) {
        nab++;
        cout << "Yes" << endl;

      } else {
        cout << "No" << endl;
      }

    } else if (c == 'b') {
      nb++;

      if (nab < a + b && nb <= b) {
        nab++;
        cout << "Yes" << endl;

      } else {
        cout << "No" << endl;
      }

    } else {
      cout << "No" << endl;
    }
  }

  return 0;
}