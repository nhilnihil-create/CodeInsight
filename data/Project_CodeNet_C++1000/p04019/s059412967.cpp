#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  
  int count = 1;
  for (int i = 0; i < s.size(); i++) {
    if (s.at(i) == 'N') {
      if (count % 2 == 0) {
        continue;
      }
      count *= 2;
    }
    else if (s.at(i) == 'E') {
      if (count % 3 == 0) {
        continue;
      }
      count *= 3;
    }
    else if (s.at(i) == 'W') {
      if (count % 5 == 0) {
        continue;
      }
      count *= 5;
    }
    else if (s.at(i) == 'S') {
      if (count % 7 == 0) {
        continue;
      }
      count *= 7;
    }
  }
  if (count % 210 == 0) {
    cout << "Yes" << endl;
  }
  else if (count % 14 == 0 && count % 3 != 0 && count % 5 != 0) {
    cout << "Yes" << endl;
  }
  else if (count % 15 == 0 && count % 2 != 0 && count % 7 != 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}

