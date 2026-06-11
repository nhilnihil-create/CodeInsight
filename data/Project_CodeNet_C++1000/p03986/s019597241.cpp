#include <iostream>
#include <string>

using namespace std;

int main () {
  string s;
  cin >> s;

  int delc = 0, pref = 0;
  for (char c : s) {
    if (c == 'S') pref++;
    else {
      if (pref > 0) {
        pref--;
        delc += 2;
      }
    }
  }

  cout << (int) s.size() - delc << endl;
}
