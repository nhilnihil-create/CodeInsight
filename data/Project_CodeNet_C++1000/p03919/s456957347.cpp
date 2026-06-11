#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  string str;
  int cou = 0;
  for(int i = 0; i < A * B; i++) {
    cin >> str;
    cou++;
    if(str == "snuke") {
      break;
    }
  }
  int X = cou % B;
  int Y = (cou - X) / B + 1;
  if(X == 0) {
    X = B;
    Y--;
  }
  string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char W = alp.at(X - 1);
  cout << W << Y << endl;
}