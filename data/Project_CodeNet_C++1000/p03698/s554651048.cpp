#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  bool b = true;
  cin >> S;
  for (int i = 0; i < (S.size() - 1); i++) {
    for (int j = i + 1; j < S.size(); j++) {
      if (S.at(i) == S.at(j)) {
        b = false;
      }
    }
  }
  if (b) {cout << "yes" << endl;}
  else {cout << "no" << endl;}
}