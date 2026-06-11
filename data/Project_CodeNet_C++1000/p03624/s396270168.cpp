#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
  string S;
  cin >> S;
  for(char c='a'; c<='z'; c++) {
    bool found = false;
    for(int i = 0; i<S.length(); i++) {
      if(S[i] == c) found = true;
    }
    if(!found) {
      cout << c << endl;
      return 0;
    }
  }
  cout << "None" << endl;
}