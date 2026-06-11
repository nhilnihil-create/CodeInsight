#include <iostream>
#include <string>

using namespace std;

int main() {
  string w;
  cin >> w;
  int ws[130] = {0};

  for (string::iterator it = w.begin(); it != w.end(); it++) {
    ws[*it]++;
  }
  int a = (int)'a';
  int z = (int)'z';
  bool ok = true;
  for (int i = a; i <= z; i++) {
    if (ws[i] % 2 == 1) {
      ok = false;
      break;
    }
  }
  if (ok) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  cout << endl;

  return 0;
}
