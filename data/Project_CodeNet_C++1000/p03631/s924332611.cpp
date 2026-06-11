#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  bool  b = true;
  for(int i = 0; i < S.size(); i++) {
    if(S.at(i) != S.at(S.size()-i-1)) {
      b = false;
    }
  }
  if(b) {
    cout << "Yes";
  }
  else {
    cout << "No";
  }
}
