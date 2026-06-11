#include <bits/stdc++.h>
using namespace std;
int main() {
  string A, B, C, X, atoA;
  cin >> A >> B >> C;
  X = "aaa";
  X.at(0) = A.at(0);
  X.at(1) = B.at(0);
  X.at(2) = C.at(0);
  atoA = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for(int i = 0; i < 26; i++) {
    if(X.at(0) == atoA.at(i)) {
      X.at(0) = atoA.at(i + 26);
      break;
    }
  }
  for(int i = 0; i < 26; i++) {
    if(X.at(1) == atoA.at(i)) {
      X.at(1) = atoA.at(i + 26);
      break;
    }
  }
  for(int i = 0; i < 26; i++) {
    if(X.at(2) == atoA.at(i)) {
      X.at(2) = atoA.at(i + 26);
      break;
    }
  }
  cout << X << endl;
}