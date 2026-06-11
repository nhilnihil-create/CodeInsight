#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  string s;
  cin >> n >> a >> b;
  cin >> s;

  int jp = 0;
  int os = 0;

  for (int i = 0; i < n; i++) {
    char c = s.at(i);
    if (c == 'a') {
      if (jp + os < a + b) {
        cout << "Yes" << endl;
        jp++;
      } else {
        cout << "No" << endl;
      }
    } else if (c == 'b') {
      if (jp + os < a + b && os < b) {
        cout << "Yes" << endl;
        os++;
      } else {
        cout << "No" << endl;
      }
    } else {
      cout << "No" << endl;
    }
  }
}
