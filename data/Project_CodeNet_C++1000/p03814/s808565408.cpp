#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  int a = 0;
  int z = 0;
  int len = s.size();
  for (int i = 0; i < len; i++) {
    if (s[i] == 'A') {
      a = i;
      break;
    }
  }
  for (int i = len - 1; i > 0; i--) {
    if (s[i] == 'Z') {
      z = i;
      break;
    }
  }
  cout << z - a + 1 << endl;
  return 0;
}
