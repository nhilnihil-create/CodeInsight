#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s[3];
  for (int i = 0; i < 3; i++) cin >> s[i];
  
  int cur = 0;
  while (s[cur].size() > 0) {
    int next = s[cur][0];
    s[cur].erase(0, 1);
    switch (next) {
      case 'a':
        cur = 0;
        break;
      case 'b':
        cur = 1;
        break;
      case 'c':
        cur = 2;
        break;
    }
  }
  
  switch (cur) {
    case 0:
      cout << "A" << endl;
      break;
    case 1:
      cout << "B" << endl;
      break;
    case 2:
      cout << "C" << endl;
      break;
  }

  return 0;
}