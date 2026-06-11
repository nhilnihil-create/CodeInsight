#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  string S;
  cin >> S;
  int b[26] = {0}; //バケット
  FOR(i, 0, S.size()) {
    b[S[i] - 'a']++;
  }
  //FOR(i, 0, 26) cout << b[i] << endl;
  FOR(i, 0, 26) {
    if (b[i] == 0) {
      cout << char('a' + i) << endl;
      return 0;
    }
  }
  cout <<  "None" << endl;
  return 0;
}

