#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  int t[10] = {0};
  int index = 0;
  for (string::iterator it = s.begin(); it != s.end(); it++) {
    if (*it == '0') {
      t[index++] = 0;
    } else if (*it == '1') {
      t[index++] = 1;
    } else if (*it == 'B') {
      if (index > 0) {
        index--;
      }
    }
  }
  for (int i = 0; i < index; i++) {
    cout<<t[i];
  }
  cout<<endl;

  return 0;
}
