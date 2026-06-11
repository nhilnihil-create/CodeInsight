#include<bits/stdc++.h>
using namespace std;

int main () {
  string S, t = "YAKI";
  cin >> S;

  bool ans = true;
  if (S.size() < 4) {
      ans = false;
    }
  else {
    for (int i = 0; i < 4; i++) {
      if (S.at(i) != t.at(i)) {
        ans = false;
      }
    }
  }
  if (ans) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}