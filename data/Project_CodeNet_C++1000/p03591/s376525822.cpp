#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  if (S.size()<4) {
    cout << "No" << endl;
  }
  else {
    if (S.at(0)=='Y' && S.at(1)=='A' && S.at(2)=='K' && S.at(3)=='I') {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
}
