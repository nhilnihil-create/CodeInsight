#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  for (int i = 0, s = S.length(); i < s; i++) {
    for (int j = i + 1; j < s; j++) {
      if(S[i] == S[j]) {
        cout << "no" << endl;
        return 0;
      }
    }
  }

  cout << "yes" << endl;
}