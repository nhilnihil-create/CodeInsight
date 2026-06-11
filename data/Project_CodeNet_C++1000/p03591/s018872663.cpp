#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  bool flag = true;
  string yaki = "YAKI";
  if (S.size() < 4) {
      flag = false;
  } else {
    for (int i; i < 4; i++) {
      if (S.at(i) != yaki.at(i)) {
        flag = false;
      }
    }
  }
  
  if (flag) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}