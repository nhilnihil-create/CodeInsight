#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;

  int qualified = 0;
  int oversea_students = 0;
  for (char c : s) {
    switch (c) {
      case 'a':
        if (qualified < a + b) {
          cout << "Yes";
          ++qualified;
        } else {
          cout << "No";
        }
        break;
      case 'b':
        ++oversea_students;
        if (qualified < a + b && oversea_students <= b) {
          cout << "Yes";
          ++qualified;
        } else {
          cout << "No";
        }
        break;
      case 'c':
        cout << "No";
        break;
    }
    cout << endl;
  }

  return 0;
}
