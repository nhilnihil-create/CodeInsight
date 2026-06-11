#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  string ans = "None";
  char c='a', cc;
  int ff=0;
  for (int i=0; i<26; i++) {
    ff=0;
    cc=(char)(c+i);
    for (int j=0; j<S.size(); j++) {
      if (S[j]==cc) {
        ff=1;
        break;
      }
    }
    if (ff==0) {
      ans = cc;
      break;
    }
  }
  cout << ans << endl;
}
