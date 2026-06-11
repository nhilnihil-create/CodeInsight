#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  if (s.size() < 4) {
    cout << "No" << endl;
    return 0;
  }
  string t = "YAKI";
  bool flag = true;
  for (int i = 0; i < 4; i++) {
    if (s[i] != t[i]) {
      flag = false;
    }
  }
  if (flag) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}