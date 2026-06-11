#include <bits/stdc++.h>
using namespace std;
int main() {
  string s,t,u;
  cin >> s >> t >> u;
  char turn = 'a';
  while (1) {
    switch (turn) {
      case 'a':
        if (s.empty()) {
          cout << "A" << endl;
          return 0;
        }
        turn = s.at(0);
        s.erase(0,1);
        break;
      case 'b':
        if (t.empty()) {
          cout << "B" << endl;
          return 0;
        }
        turn = t.at(0);
        t.erase(0,1);
        break;
      case 'c':
        if (u.empty()) {
          cout << "C" << endl;
          return 0;
        }
        turn = u.at(0);
        u.erase(0,1);
        break;
    }
  }
}