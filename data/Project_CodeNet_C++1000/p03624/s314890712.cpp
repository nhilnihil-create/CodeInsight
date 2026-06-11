#include <iostream>

using namespace std;

int main() {
  string s;
  int d[26] = {0};
  cin >> s;
  int offset = 'a';
  for (int i = 0; i < s.size(); i++) {
    int j = s[i] - offset;
    d[j]++;
  }
  bool ok = false;
  for (int i = 0; i < 26; i++) {
    if (d[i] == 0) {
      char c = (char)(i + offset);
      cout << c << endl;
      ok = true;
      break;
    }
  }
  if (!ok) {
    cout << "None" << endl;
  }
  return 0;
}
