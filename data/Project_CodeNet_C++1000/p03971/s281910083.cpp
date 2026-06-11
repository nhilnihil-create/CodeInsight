#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  string S;
  int d = 0;
  int f = 0;
  int ff = 0;

  cin >> N >> A >> B >> S;

  for (int i = 0; i < S.size(); i++)
  {
    char c = S[i];
    if (c == 'a') d++;
    if (c == 'b') {
      f++;
      if (f <= B) {
        ff = f;
      }
      else {
        ff = B;
      }
    }
    if (d + ff <= A + B && (c == 'a' || c == 'b' && f <= B)) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
}