#include <bits/stdc++.h>
using namespace std;
int main() {
  string S[3];
  cin >> S[0] >> S[1] >> S[2];
  int abc[3] = {0,0,0};
  for (char player = 'a'; true; player = S[player-'a'][abc[player-'a']++]) {
    if (abc[player-'a'] == S[player-'a'].length()) {
      cout << (char)('A'-'a'+player);
      return 0;
    }
  }
}