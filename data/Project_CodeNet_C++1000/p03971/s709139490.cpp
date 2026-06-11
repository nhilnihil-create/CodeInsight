#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  string S;
  int t = 0;
  int f = 0;

  cin >> N >> A >> B >> S;

  for (int i = 0; i < S.size(); i++)
  {
    char c = S[i];
    if (c == 'a') {
      if (t < A + B) {
        cout << "Yes" << endl;
        t++;
      }
      else {
        cout << "No" << endl;
      }
    }
    if (c == 'b') {
      if (t < A + B && f < B) {
        cout << "Yes" << endl;
        t++;
        f++;
      }
      else {
        cout << "No" << endl;
      }
    }
    if (c == 'c') {
      cout << "No" << endl;
    }
  }
}