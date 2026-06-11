#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int D = S.size();
  vector<int>A(D);
  for (int i = 0; i < D; i++) {
    A.at(i) = S.at(i) - '0';
  }
  sort(A.begin(), A.end());
  for (int i = 0; i < D-1; i++) {
    if (A.at(0) != 49){
      cout << 'a' << endl;
      return 0;
    }
    if (A.at(i+1) - A.at(i) > 1){
      int C = A.at(i)-48;
      cout << (char)('a'+C) << endl;
      return 0;
    }
    if (i == D-2 && A.at(i+1) != 74){
      int C = A.at(i+1)-48;
      cout << (char)('a'+C) << endl;
      return 0;
    }
  }
  cout << "None" << endl;
}

