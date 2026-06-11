#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  int c[30] = {0};
  int a = 'a';
  int z = s.size();
  bool ok = true;
  for (int i = 0; i < z; i++) {
    int p = s[i] - a;
    c[p]++;
    if (c[p] > 1) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
  return 0;
}
