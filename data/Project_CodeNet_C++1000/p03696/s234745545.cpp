#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int L = 0, R = 0;
  int l = 0, r = 0;
  for (int i = 0; i < N; i++) {
    if (S.at(i) == ')') {
      if (l) {
        l--;
        continue;
      } else {
        L++;
      }
    } else {
      l++;
    }
  }
  reverse(S.begin(), S.end());
  for (int i = 0; i < N; i++) {
    if (S.at(i) == '(') {
      if (r) {
        r--;
        continue;
      } else {
        R++;
      }
    } else {
      r++;
    }
  }
  reverse(S.begin(), S.end());
  while (L--) cout << "(";
  cout << S;
  while (R--) cout << ")";
  cout << "\n";
}