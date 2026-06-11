#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int ff=1, l=0;
  for (int i=S.size()-3; i>=0; i-=2) {
    ff=1;
    for (int j=0; j<(i+1)/2; j++) {
      if (S[j]!=S[j+(i+1)/2]) {
        ff=0;
      }
    }
    if (ff==1) {
      l=i+1;
      break;
    }
  }
  cout << l << endl;
}
