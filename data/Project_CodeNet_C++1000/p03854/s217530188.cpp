#include <bits/stdc++.h>
#define N 4
using namespace std;
int main() {
  string S, T[N] = {"dream", "dreamer", "erase", "eraser"};
  cin >> S;
  bool valid;
  do {
    valid = false;
    for (int i = 0; i < N && !valid; i++) {
      if (S.length() >= T[i].length() && S.substr(S.length()-T[i].length()) == T[i]) {
        S.erase(S.length()-T[i].length());
        valid = true;
      }
    }
  } while (!S.empty() && valid);
  if (S.empty()) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}