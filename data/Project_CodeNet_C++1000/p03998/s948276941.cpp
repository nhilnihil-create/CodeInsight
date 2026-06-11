#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string a, b, c;
  cin >> a >> b >> c;
  
  char next = 'a';
  
  while (1) {
    if (next == 'a') {
      if (a.size() == 0) {
        cout << 'A' << endl;
        break;
      }
      next = a.at(0);
      a.erase(0, 1);
    }
    if (next == 'b') {
      if (b.size() == 0) {
        cout << 'B' << endl;
        break;
      }
      next = b.at(0);
      b.erase(0, 1);
    }
    if (next == 'c') {
      if (c.size() == 0) {
        cout << 'C' << endl;
        break;
      }
      next = c.at(0);
      c.erase(0, 1);
    }
  }
  
}