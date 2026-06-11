#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  int result = 0;
  for (int i = 0, j = 0; i < s.size(); i++) {
    if (s[i] == 'g') {
      if (j > 0) {
        j--;
        result++;
      } else {
        j++;
      }
    } else {
      if (j > 0) {
        j--;
      } else {
        j++;
        result--;
      }
    }
  }
  cout << result;
  return 0;
}