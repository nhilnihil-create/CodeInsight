#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int left = 0 ,right = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') {
      left += 1;
    } else {
      if (left != 0) {
        left -= 1;
      } else {
        right += 1;
      }
    }
  }
  cout << string(right, '(') + s + string(left, ')') << endl;
  return 0;
}
